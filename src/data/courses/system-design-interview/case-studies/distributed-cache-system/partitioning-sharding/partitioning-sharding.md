## Why Partitioning is Essential

From our capacity estimation, we determined that:
- **8.2 TB total memory needed** - No single machine can handle this
- **1M QPS total load** - Distributed processing required
- **Horizontal scaling mandatory** - Must split data across nodes

Partitioning (sharding) is the technique that enables horizontal scaling by distributing data across multiple nodes.

## Partitioning Approaches

### 1. Range-Based Partitioning

**How it works:**
- Divide key space into ranges (A-F, G-M, N-S, T-Z)
- Each node handles a specific range
- Simple to understand and implement

```
Node 1: keys starting with A-F
Node 2: keys starting with G-M  
Node 3: keys starting with N-S
Node 4: keys starting with T-Z
```

**Pros:**
- Simple range queries
- Easy to understand
- Good for sequential access patterns

**Cons:**
- **Hot spots**: Popular key prefixes overload single nodes
- **Uneven distribution**: Some ranges may have more keys
- **Difficult rebalancing**: Moving ranges is complex

**Verdict:** ❌ Not suitable for cache workloads with unpredictable key patterns

### 2. Hash-Based Partitioning (Modulo)

**How it works:**
- Hash the key and take modulo of node count
- `node = hash(key) % N`

```python
def get_node(key, num_nodes):
    return hash(key) % num_nodes

# Examples with 4 nodes:
get_node("user:123") → hash("user:123") % 4 = 2
get_node("session:abc") → hash("session:abc") % 4 = 1
```

**Pros:**
- Even distribution of keys
- Simple to implement
- Good load balancing

**Cons:**
- **Massive reshuffling**: Adding/removing nodes changes most key locations
- **Downtime required**: Must remap and move ~50% of data
- **Thundering herd**: Cache misses during rebalancing

**Example of the problem:**
```
With 4 nodes: hash("user:123") % 4 = 2 (Node 2)
Add 1 node (5 total): hash("user:123") % 5 = 3 (Node 3)
Result: Key moved from Node 2 to Node 3
```

**Verdict:** ❌ Unacceptable for production systems requiring availability

### 3. Consistent Hashing

**How it works:**
- Map both keys and nodes to points on a circular hash ring
- Each key is assigned to the first node clockwise from its position
- Adding/removing nodes only affects adjacent keys

```
Hash Ring (0 to 2^32-1):

    Node A (hash=100)
         ↓
    [0]--[100]--[500]--[1000]--[1500]--[0]
              ↑         ↑         ↑
         Node B      Node C    Node D
        (hash=500)  (hash=1000) (hash=1500)

Key "user:123" (hash=750) → goes to Node C (first node clockwise)
```

**Pros:**
- **Minimal data movement**: Only ~1/N keys move when adding/removing nodes
- **No downtime**: Can add nodes without stopping service
- **Fault tolerant**: Node failures only affect adjacent keys

**Cons:**
- **Uneven distribution**: Nodes may get unequal key ranges by chance
- **Hot spots**: Popular keys can still overload single nodes

**Verdict:** ✅ Good foundation, but needs virtual nodes

### 4. Consistent Hashing with Virtual Nodes

**How it works:**
- Each physical node gets multiple positions (virtual nodes) on the ring
- Typically 150-500 virtual nodes per physical node
- Keys are distributed across virtual nodes, which map to physical nodes

```
Physical Node A has virtual nodes at positions: 100, 300, 800, 1200, 1600
Physical Node B has virtual nodes at positions: 200, 600, 900, 1400, 1800
Physical Node C has virtual nodes at positions: 150, 450, 750, 1050, 1350

Hash Ring with Virtual Nodes:
[0]--[100A]--[150C]--[200B]--[300A]--[450C]--[500]--[600B]--[750C]--[800A]--[900B]--[1050C]--[1200A]--[1350C]--[1400B]--[1600A]--[1800B]--[0]
```

**Benefits:**
- **Even distribution**: Statistical guarantee of balanced load
- **Smooth rebalancing**: Adding nodes takes virtual nodes from all existing nodes
- **Fault tolerance**: Node failure distributes load across all remaining nodes

**Implementation:**
```python
class ConsistentHash:
    def __init__(self, nodes, virtual_nodes=150):
        self.virtual_nodes = virtual_nodes
        self.ring = {}
        self.sorted_keys = []
        
        for node in nodes:
            self.add_node(node)
    
    def add_node(self, node):
        for i in range(self.virtual_nodes):
            virtual_key = f"{node}:{i}"
            hash_value = self._hash(virtual_key)
            self.ring[hash_value] = node
        
        self.sorted_keys = sorted(self.ring.keys())
    
    def remove_node(self, node):
        for i in range(self.virtual_nodes):
            virtual_key = f"{node}:{i}"
            hash_value = self._hash(virtual_key)
            del self.ring[hash_value]
        
        self.sorted_keys = sorted(self.ring.keys())
    
    def get_node(self, key):
        if not self.ring:
            return None
        
        hash_value = self._hash(key)
        
        # Find first node clockwise
        for ring_key in self.sorted_keys:
            if hash_value <= ring_key:
                return self.ring[ring_key]
        
        # Wrap around to first node
        return self.ring[self.sorted_keys[0]]
    
    def _hash(self, key):
        return hash(key) % (2**32)
```

**Verdict:** ✅ Chosen approach for distributed cache

## Hash Slot Implementation (Redis Cluster Approach)

Instead of a continuous hash ring, we can use discrete hash slots:

### Hash Slot Design

```
Total slots: 16,384 (2^14)
Hash function: CRC16 (fast, good distribution)
Slot assignment: CRC16(key) % 16384

Example:
key "user:123" → CRC16("user:123") = 31,475 → 31,475 % 16,384 = 15,091
key goes to slot 15,091
```

### Slot-to-Node Mapping

```python
class HashSlotCluster:
    def __init__(self):
        self.slots = [None] * 16384  # 16K slots
        self.nodes = {}
    
    def add_node(self, node_id, slot_ranges):
        self.nodes[node_id] = node_id
        for start, end in slot_ranges:
            for slot in range(start, end + 1):
                self.slots[slot] = node_id
    
    def get_node_for_key(self, key):
        slot = self.crc16(key) % 16384
        return self.slots[slot]
    
    def migrate_slot(self, slot, from_node, to_node):
        # Move slot ownership
        self.slots[slot] = to_node
        # Trigger data migration (handled separately)
        self.migrate_slot_data(slot, from_node, to_node)
```

### Benefits of Hash Slots

1. **Precise control**: Exact slot assignment and migration
2. **Atomic migration**: Move one slot at a time
3. **Simple routing**: O(1) lookup for key → node mapping
4. **Redis compatibility**: Same approach as Redis Cluster

## Handling Hot Keys

Hot keys can overwhelm single nodes even with good partitioning:

### Problem Scenario
```
Viral video key "video:trending" gets 100K QPS
All requests go to one shard → node overloaded
Other shards idle while one shard struggles
```

### Solution 1: Client-Side Caching

```python
class CacheClient:
    def __init__(self):
        self.local_cache = LRUCache(maxsize=1000)
        self.hot_key_threshold = 1000  # requests per second
        self.key_counters = {}
    
    def get(self, key):
        # Check local cache first for hot keys
        if self.is_hot_key(key):
            local_value = self.local_cache.get(key)
            if local_value:
                return local_value
        
        # Fetch from distributed cache
        value = self.distributed_get(key)
        
        # Cache locally if hot
        if self.is_hot_key(key):
            self.local_cache.set(key, value, ttl=60)  # 1 minute local TTL
        
        return value
    
    def is_hot_key(self, key):
        # Track key access frequency
        current_time = time.time()
        if key not in self.key_counters:
            self.key_counters[key] = []
        
        # Add current access
        self.key_counters[key].append(current_time)
        
        # Remove old accesses (older than 1 second)
        cutoff = current_time - 1.0
        self.key_counters[key] = [t for t in self.key_counters[key] if t > cutoff]
        
        return len(self.key_counters[key]) > self.hot_key_threshold
```

### Solution 2: Key Sharding

```python
def shard_hot_key(key, value, shard_count=16):
    """Split hot key across multiple shards"""
    for i in range(shard_count):
        sharded_key = f"{key}:shard:{i}"
        cache.set(sharded_key, value)

def get_from_sharded_key(key, shard_count=16):
    """Read from random shard"""
    shard_id = random.randint(0, shard_count - 1)
    sharded_key = f"{key}:shard:{shard_id}"
    return cache.get(sharded_key)
```

### Solution 3: Read Replicas for Hot Keys

```python
class HotKeyHandler:
    def __init__(self):
        self.hot_key_replicas = {}  # key → list of replica nodes
    
    def handle_hot_key(self, key):
        if key in self.hot_key_replicas:
            # Route reads to replicas
            replica = random.choice(self.hot_key_replicas[key])
            return replica.get(key)
        else:
            # Normal routing
            return self.get_primary_node(key).get(key)
    
    def promote_to_hot_key(self, key):
        # Create additional replicas for this key
        primary = self.get_primary_node(key)
        replicas = self.create_replicas_for_key(key, count=3)
        self.hot_key_replicas[key] = replicas
```

## Data Migration

When adding or removing nodes, we need to migrate data:

### Slot Migration Process

```python
class SlotMigrator:
    def migrate_slot(self, slot, source_node, target_node):
        # 1. Mark slot as migrating
        self.mark_slot_migrating(slot, source_node, target_node)
        
        # 2. Get all keys in slot
        keys = source_node.scan_slot(slot)
        
        # 3. Migrate keys in batches
        batch_size = 100
        for i in range(0, len(keys), batch_size):
            batch = keys[i:i + batch_size]
            self.migrate_key_batch(batch, source_node, target_node)
        
        # 4. Update slot ownership
        self.update_slot_ownership(slot, target_node)
        
        # 5. Clean up source data
        source_node.delete_slot_data(slot)
    
    def migrate_key_batch(self, keys, source, target):
        # Get key-value pairs from source
        data = source.dump_keys(keys)
        
        # Restore on target
        target.restore_keys(data)
        
        # Verify migration
        for key in keys:
            source_value = source.get(key)
            target_value = target.get(key)
            assert source_value == target_value
```

### Handling Requests During Migration

```python
def handle_request_during_migration(key, operation):
    slot = get_slot(key)
    
    if slot in migrating_slots:
        source_node = migrating_slots[slot]['source']
        target_node = migrating_slots[slot]['target']
        
        if operation == 'GET':
            # Try target first, fallback to source
            value = target_node.get(key)
            if value is None:
                value = source_node.get(key)
            return value
        
        elif operation in ['SET', 'DEL']:
            # Write to both nodes during migration
            source_node.execute(operation, key)
            target_node.execute(operation, key)
    
    else:
        # Normal routing
        node = get_node_for_slot(slot)
        return node.execute(operation, key)
```

## Hash Tags for Related Keys

Sometimes we need related keys to be on the same shard:

### Problem
```
User session: "session:user123"  → Shard A
User profile: "profile:user123"  → Shard B
User cart:    "cart:user123"     → Shard C

Cannot perform atomic operations across shards
```

### Solution: Hash Tags
```python
def get_slot_with_hash_tag(key):
    # Look for hash tag pattern {tag}
    start = key.find('{')
    if start != -1:
        end = key.find('}', start)
        if end != -1 and end > start + 1:
            # Use content within {} for hashing
            hash_key = key[start + 1:end]
            return crc16(hash_key) % 16384
    
    # No hash tag, use full key
    return crc16(key) % 16384

# Usage:
# All these keys go to same shard
session_key = "{user123}:session"
profile_key = "{user123}:profile"  
cart_key = "{user123}:cart"
```

## Monitoring and Observability

### Key Metrics to Track

```python
class ShardingMetrics:
    def __init__(self):
        self.metrics = {
            'keys_per_shard': {},      # Distribution of keys
            'qps_per_shard': {},       # Request rate per shard
            'memory_per_shard': {},    # Memory usage per shard
            'hot_keys': {},            # Keys with high access rate
            'migration_progress': {},   # Ongoing migrations
        }
    
    def record_request(self, key, shard):
        current_time = time.time()
        
        # Track QPS per shard
        if shard not in self.metrics['qps_per_shard']:
            self.metrics['qps_per_shard'][shard] = []
        self.metrics['qps_per_shard'][shard].append(current_time)
        
        # Track hot keys
        if key not in self.metrics['hot_keys']:
            self.metrics['hot_keys'][key] = []
        self.metrics['hot_keys'][key].append(current_time)
    
    def get_shard_balance_score(self):
        """Calculate how evenly distributed the load is"""
        qps_values = [len(requests) for requests in self.metrics['qps_per_shard'].values()]
        if not qps_values:
            return 1.0
        
        mean_qps = sum(qps_values) / len(qps_values)
        variance = sum((qps - mean_qps) ** 2 for qps in qps_values) / len(qps_values)
        
        # Lower variance = better balance
        return 1.0 / (1.0 + variance / mean_qps)
```

### Alerting Thresholds

```yaml
shard_imbalance:
  threshold: balance_score < 0.7
  action: Consider rebalancing

hot_key_detected:
  threshold: key_qps > 10000
  action: Enable client-side caching

shard_overload:
  threshold: shard_qps > 50000
  action: Scale out or migrate slots

memory_pressure:
  threshold: shard_memory > 80%
  action: Add nodes or enable eviction
```

## Summary

Our partitioning strategy provides:

1. **Consistent Hashing with Virtual Nodes**: Even distribution and minimal data movement
2. **Hash Slots**: Precise control over data placement and migration
3. **Hot Key Handling**: Multiple strategies to prevent single-node overload
4. **Atomic Operations**: Hash tags for related keys
5. **Live Migration**: Zero-downtime node addition/removal
6. **Comprehensive Monitoring**: Track balance and performance

This partitioning foundation enables our distributed cache to scale horizontally while maintaining high performance and availability.

Next, we'll design the replication and consistency models that provide fault tolerance and data durability.