## Why Memory Management is Critical

In distributed caches, memory is the most expensive and constrained resource:

- **RAM costs 10-100x more than disk** - Every byte must be used efficiently
- **Performance depends on memory** - Disk access violates sub-millisecond latency requirements
- **Memory pressure causes cascading failures** - OOM kills processes, triggers failovers
- **Eviction affects hit rates** - Poor eviction policies reduce cache effectiveness

## Memory Layout and Overhead

### Redis Memory Overhead Analysis

```
For a simple key-value pair "user:123" → "john_doe":

Raw data: 8 bytes (key) + 8 bytes (value) = 16 bytes

Actual memory usage:
- Key object: 8 + 24 (object header) + 8 (SDS header) = 40 bytes
- Value object: 8 + 24 (object header) + 8 (SDS header) = 40 bytes  
- Hash table entry: 24 bytes (pointer + hash + next)
- Expiry metadata: 16 bytes (if TTL set)

Total: 40 + 40 + 24 + 16 = 120 bytes
Overhead: 104 bytes (650% overhead!)
```

### Memory Optimization Strategies

#### 1. Small Object Encoding

For small collections, use compact representations:

```python
class SmallObjectOptimizer:
    def __init__(self):
        self.small_hash_threshold = 512    # bytes
        self.small_list_threshold = 128    # elements
        self.small_set_threshold = 128     # elements
    
    def encode_hash(self, hash_data):
        if self.estimate_size(hash_data) < self.small_hash_threshold:
            # Use ziplist encoding - flat array
            return self.encode_as_ziplist(hash_data)
        else:
            # Use hash table encoding
            return self.encode_as_hashtable(hash_data)
    
    def encode_as_ziplist(self, data):
        """
        Ziplist format: [total_bytes][num_entries][entry1][entry2]...[end]
        No pointers, no per-entry overhead
        """
        buffer = bytearray()
        buffer.extend(len(data).to_bytes(4, 'little'))  # num_entries
        
        for key, value in data.items():
            # Encode key
            key_bytes = key.encode('utf-8')
            buffer.extend(len(key_bytes).to_bytes(2, 'little'))
            buffer.extend(key_bytes)
            
            # Encode value  
            value_bytes = value.encode('utf-8')
            buffer.extend(len(value_bytes).to_bytes(2, 'little'))
            buffer.extend(value_bytes)
        
        buffer.append(0xFF)  # End marker
        return bytes(buffer)
```

#### 2. Integer Encoding

Store integers efficiently without string conversion:

```python
class IntegerOptimizer:
    def encode_value(self, value):
        if isinstance(value, int):
            if -2**31 <= value < 2**31:
                return ('int32', value.to_bytes(4, 'little', signed=True))
            elif -2**63 <= value < 2**63:
                return ('int64', value.to_bytes(8, 'little', signed=True))
        
        # Fallback to string encoding
        return ('string', value.encode('utf-8'))
    
    def decode_value(self, encoding_type, data):
        if encoding_type == 'int32':
            return int.from_bytes(data, 'little', signed=True)
        elif encoding_type == 'int64':
            return int.from_bytes(data, 'little', signed=True)
        else:
            return data.decode('utf-8')
```

## Eviction Policies

When memory is full, we must evict keys to make room for new data.

### 1. LRU (Least Recently Used)

**Algorithm:**
- Track access time for each key
- Evict the key that was accessed longest ago
- Good for temporal locality workloads

**Naive Implementation (Too Expensive):**
```python
class NaiveLRU:
    def __init__(self, maxsize):
        self.maxsize = maxsize
        self.cache = {}
        self.access_order = []  # Expensive to maintain!
    
    def get(self, key):
        if key in self.cache:
            # Move to end (most recent)
            self.access_order.remove(key)  # O(n) operation!
            self.access_order.append(key)
            return self.cache[key]
        return None
    
    def set(self, key, value):
        if len(self.cache) >= self.maxsize:
            # Evict least recently used
            lru_key = self.access_order.pop(0)  # O(n) operation!
            del self.cache[lru_key]
        
        self.cache[key] = value
        self.access_order.append(key)
```

**Redis Approximate LRU (Efficient):**
```python
class ApproximateLRU:
    def __init__(self, maxsize, sample_size=5):
        self.maxsize = maxsize
        self.sample_size = sample_size
        self.cache = {}
        self.current_time = 0
    
    def get(self, key):
        if key in self.cache:
            # Update access time (24-bit timestamp)
            self.cache[key]['last_access'] = self.current_time
            self.current_time += 1
            return self.cache[key]['value']
        return None
    
    def set(self, key, value):
        if len(self.cache) >= self.maxsize and key not in self.cache:
            self.evict_lru_key()
        
        self.cache[key] = {
            'value': value,
            'last_access': self.current_time
        }
        self.current_time += 1
    
    def evict_lru_key(self):
        # Sample random keys and evict the one with oldest access time
        sample_keys = random.sample(list(self.cache.keys()), 
                                   min(self.sample_size, len(self.cache)))
        
        lru_key = min(sample_keys, 
                     key=lambda k: self.cache[k]['last_access'])
        
        del self.cache[lru_key]
```

### 2. LFU (Least Frequently Used)

**Algorithm:**
- Track access frequency for each key
- Evict the key with lowest access frequency
- Good for skewed access patterns (Zipf distribution)

**Implementation with Decay:**
```python
class LFUWithDecay:
    def __init__(self, maxsize, decay_factor=0.9):
        self.maxsize = maxsize
        self.decay_factor = decay_factor
        self.cache = {}
        self.global_time = 0
        self.decay_interval = 1000  # Decay every 1000 operations
    
    def get(self, key):
        if key in self.cache:
            self.cache[key]['frequency'] += 1
            self.cache[key]['last_access'] = self.global_time
            self.global_time += 1
            
            if self.global_time % self.decay_interval == 0:
                self.decay_frequencies()
            
            return self.cache[key]['value']
        return None
    
    def set(self, key, value):
        if len(self.cache) >= self.maxsize and key not in self.cache:
            self.evict_lfu_key()
        
        self.cache[key] = {
            'value': value,
            'frequency': 1,
            'last_access': self.global_time
        }
        self.global_time += 1
    
    def decay_frequencies(self):
        """Decay all frequencies to prevent old keys from staying forever"""
        for key in self.cache:
            self.cache[key]['frequency'] *= self.decay_factor
    
    def evict_lfu_key(self):
        # Find key with minimum frequency (break ties with LRU)
        lfu_key = min(self.cache.keys(), 
                     key=lambda k: (self.cache[k]['frequency'], 
                                   self.cache[k]['last_access']))
        del self.cache[lfu_key]
```

### 3. TTL-Based Eviction

**Algorithm:**
- Evict keys that have expired based on TTL
- Combination of lazy and active expiration

**Implementation:**
```python
class TTLEviction:
    def __init__(self):
        self.cache = {}
        self.expiry_times = {}  # key → expiry_timestamp
        self.active_expiry_interval = 0.1  # 100ms
        self.expiry_sample_size = 20
        
        # Start background expiry thread
        self.start_active_expiry()
    
    def set(self, key, value, ttl=None):
        self.cache[key] = value
        if ttl:
            self.expiry_times[key] = time.time() + ttl
    
    def get(self, key):
        # Lazy expiration check
        if self.is_expired(key):
            self.delete_key(key)
            return None
        
        return self.cache.get(key)
    
    def is_expired(self, key):
        if key not in self.expiry_times:
            return False
        return time.time() > self.expiry_times[key]
    
    def delete_key(self, key):
        self.cache.pop(key, None)
        self.expiry_times.pop(key, None)
    
    def start_active_expiry(self):
        def active_expiry_worker():
            while True:
                self.active_expire_cycle()
                time.sleep(self.active_expiry_interval)
        
        thread = threading.Thread(target=active_expiry_worker, daemon=True)
        thread.start()
    
    def active_expire_cycle(self):
        """Sample random keys and expire any that are past TTL"""
        if not self.expiry_times:
            return
        
        # Sample random keys with TTL
        sample_keys = random.sample(
            list(self.expiry_times.keys()),
            min(self.expiry_sample_size, len(self.expiry_times))
        )
        
        expired_count = 0
        for key in sample_keys:
            if self.is_expired(key):
                self.delete_key(key)
                expired_count += 1
        
        # If >25% of sampled keys were expired, run another cycle immediately
        if expired_count > len(sample_keys) * 0.25:
            self.active_expire_cycle()
```

### 4. Random Eviction

**Algorithm:**
- Evict random keys when memory is full
- Surprisingly effective for uniform access patterns
- Lowest CPU overhead

```python
class RandomEviction:
    def __init__(self, maxsize):
        self.maxsize = maxsize
        self.cache = {}
    
    def set(self, key, value):
        if len(self.cache) >= self.maxsize and key not in self.cache:
            # Evict random key
            random_key = random.choice(list(self.cache.keys()))
            del self.cache[random_key]
        
        self.cache[key] = value
```

## Memory Pressure Handling

### Memory Usage Monitoring

```python
class MemoryMonitor:
    def __init__(self, max_memory_bytes):
        self.max_memory = max_memory_bytes
        self.warning_threshold = 0.75  # 75%
        self.critical_threshold = 0.90  # 90%
        self.eviction_threshold = 0.95  # 95%
    
    def get_memory_usage(self):
        """Get current memory usage in bytes"""
        import psutil
        process = psutil.Process()
        return process.memory_info().rss
    
    def get_memory_ratio(self):
        return self.get_memory_usage() / self.max_memory
    
    def check_memory_pressure(self):
        ratio = self.get_memory_ratio()
        
        if ratio > self.eviction_threshold:
            return 'EVICTION_NEEDED'
        elif ratio > self.critical_threshold:
            return 'CRITICAL'
        elif ratio > self.warning_threshold:
            return 'WARNING'
        else:
            return 'OK'
    
    def calculate_eviction_target(self):
        """Calculate how much memory to free"""
        current_usage = self.get_memory_usage()
        target_usage = self.max_memory * 0.80  # Target 80% usage
        
        if current_usage > target_usage:
            return current_usage - target_usage
        return 0
```

### Adaptive Eviction

```python
class AdaptiveEviction:
    def __init__(self):
        self.eviction_policies = {
            'lru': ApproximateLRU(maxsize=1000000),
            'lfu': LFUWithDecay(maxsize=1000000),
            'random': RandomEviction(maxsize=1000000),
            'ttl': TTLEviction()
        }
        self.current_policy = 'lru'
        self.policy_performance = {}
        self.evaluation_interval = 10000  # operations
        self.operation_count = 0
    
    def evict_keys(self, target_bytes):
        policy = self.eviction_policies[self.current_policy]
        
        bytes_freed = 0
        while bytes_freed < target_bytes:
            key_to_evict = policy.select_eviction_candidate()
            if not key_to_evict:
                break
            
            key_size = self.estimate_key_size(key_to_evict)
            self.delete_key(key_to_evict)
            bytes_freed += key_size
    
    def adapt_eviction_policy(self):
        """Switch to better performing eviction policy"""
        current_hit_rate = self.calculate_hit_rate()
        
        if self.current_policy not in self.policy_performance:
            self.policy_performance[self.current_policy] = []
        
        self.policy_performance[self.current_policy].append(current_hit_rate)
        
        # Try different policy if current one is underperforming
        if len(self.policy_performance[self.current_policy]) > 5:
            avg_performance = sum(self.policy_performance[self.current_policy][-5:]) / 5
            
            if avg_performance < 0.85:  # Less than 85% hit rate
                self.try_different_policy()
    
    def try_different_policy(self):
        """Switch to the policy with best historical performance"""
        best_policy = self.current_policy
        best_performance = 0
        
        for policy, performance_history in self.policy_performance.items():
            if performance_history:
                avg_performance = sum(performance_history[-10:]) / min(10, len(performance_history))
                if avg_performance > best_performance:
                    best_performance = avg_performance
                    best_policy = policy
        
        if best_policy != self.current_policy:
            print(f"Switching eviction policy from {self.current_policy} to {best_policy}")
            self.current_policy = best_policy
```

## Memory Fragmentation

### Understanding Fragmentation

```python
class FragmentationMonitor:
    def __init__(self):
        self.allocated_memory = 0
        self.used_memory = 0
    
    def calculate_fragmentation_ratio(self):
        """
        Fragmentation ratio = RSS (allocated) / Used memory
        
        Ratio > 1.5 indicates significant fragmentation
        Ratio > 2.0 indicates severe fragmentation
        """
        if self.used_memory == 0:
            return 1.0
        
        return self.allocated_memory / self.used_memory
    
    def should_defragment(self):
        ratio = self.calculate_fragmentation_ratio()
        return ratio > 1.5
    
    def estimate_fragmentation_waste(self):
        return self.allocated_memory - self.used_memory
```

### Active Defragmentation

```python
class ActiveDefragmenter:
    def __init__(self):
        self.defrag_threshold = 1.5  # fragmentation ratio
        self.defrag_cpu_percentage = 5  # Max 5% CPU for defrag
        self.defrag_interval = 60  # Check every 60 seconds
    
    def start_defragmentation(self):
        def defrag_worker():
            while True:
                if self.should_run_defrag():
                    self.run_defrag_cycle()
                time.sleep(self.defrag_interval)
        
        thread = threading.Thread(target=defrag_worker, daemon=True)
        thread.start()
    
    def run_defrag_cycle(self):
        """Move objects to reduce fragmentation"""
        start_time = time.time()
        cpu_budget = self.defrag_interval * (self.defrag_cpu_percentage / 100)
        
        # Find fragmented memory regions
        fragmented_objects = self.find_fragmented_objects()
        
        for obj in fragmented_objects:
            if time.time() - start_time > cpu_budget:
                break  # Don't exceed CPU budget
            
            # Move object to contiguous memory region
            self.relocate_object(obj)
    
    def find_fragmented_objects(self):
        """Identify objects in fragmented memory regions"""
        # This would integrate with the memory allocator
        # to identify objects that could benefit from relocation
        pass
    
    def relocate_object(self, obj):
        """Move object to less fragmented memory region"""
        # Allocate new memory
        new_location = self.allocate_contiguous_memory(obj.size)
        
        # Copy data
        new_location.copy_from(obj)
        
        # Update references
        self.update_references(obj, new_location)
        
        # Free old memory
        self.free_memory(obj)
```

## Memory-Efficient Data Structures

### Compressed Lists

```python
class CompressedList:
    def __init__(self):
        self.data = bytearray()
        self.length = 0
    
    def append(self, value):
        """Append value using variable-length encoding"""
        if isinstance(value, int):
            encoded = self.encode_varint(value)
        else:
            encoded = self.encode_string(value)
        
        self.data.extend(encoded)
        self.length += 1
    
    def encode_varint(self, value):
        """Variable-length integer encoding"""
        result = bytearray()
        while value >= 0x80:
            result.append((value & 0x7F) | 0x80)
            value >>= 7
        result.append(value & 0x7F)
        return result
    
    def encode_string(self, value):
        """Length-prefixed string encoding"""
        value_bytes = value.encode('utf-8')
        length_bytes = self.encode_varint(len(value_bytes))
        return length_bytes + value_bytes
```

### Bloom Filters for Negative Lookups

```python
class BloomFilter:
    def __init__(self, capacity, error_rate=0.01):
        self.capacity = capacity
        self.error_rate = error_rate
        
        # Calculate optimal parameters
        self.bit_array_size = self.calculate_bit_array_size()
        self.hash_count = self.calculate_hash_count()
        
        self.bit_array = bytearray(self.bit_array_size // 8)
    
    def calculate_bit_array_size(self):
        """Optimal bit array size for given capacity and error rate"""
        import math
        return int(-self.capacity * math.log(self.error_rate) / (math.log(2) ** 2))
    
    def calculate_hash_count(self):
        """Optimal number of hash functions"""
        import math
        return int(self.bit_array_size * math.log(2) / self.capacity)
    
    def add(self, key):
        """Add key to bloom filter"""
        for i in range(self.hash_count):
            hash_value = self.hash_function(key, i) % self.bit_array_size
            byte_index = hash_value // 8
            bit_index = hash_value % 8
            self.bit_array[byte_index] |= (1 << bit_index)
    
    def might_contain(self, key):
        """Check if key might be in the set (no false negatives)"""
        for i in range(self.hash_count):
            hash_value = self.hash_function(key, i) % self.bit_array_size
            byte_index = hash_value // 8
            bit_index = hash_value % 8
            
            if not (self.bit_array[byte_index] & (1 << bit_index)):
                return False  # Definitely not in set
        
        return True  # Might be in set
    
    def hash_function(self, key, seed):
        """Simple hash function with seed"""
        import hashlib
        return int(hashlib.md5(f"{key}:{seed}".encode()).hexdigest(), 16)

# Usage in cache
class CacheWithBloomFilter:
    def __init__(self):
        self.cache = {}
        self.bloom_filter = BloomFilter(capacity=1000000)
    
    def get(self, key):
        # Quick negative lookup
        if not self.bloom_filter.might_contain(key):
            return None  # Definitely not in cache
        
        # Might be in cache, check actual storage
        return self.cache.get(key)
    
    def set(self, key, value):
        self.cache[key] = value
        self.bloom_filter.add(key)
```

## Data Persistence Strategies

While caches are primarily in-memory, persistence is critical for:
- **Crash recovery** - Restore data after process restart
- **Warm cache startup** - Avoid cold start performance degradation
- **Durability guarantees** - Some use cases require data persistence
- **Backup and replication** - Transfer data between nodes

### RDB (Redis Database) - Point-in-Time Snapshots

**Concept**: Periodically save entire dataset to disk as a binary snapshot.

**Implementation:**
```python
class RDBPersistence:
    def __init__(self, snapshot_interval=300):  # 5 minutes
        self.snapshot_interval = snapshot_interval
        self.last_snapshot_time = time.time()
        self.snapshot_path = "/var/lib/cache/dump.rdb"
        self.temp_snapshot_path = "/var/lib/cache/dump.rdb.tmp"
        
        # Start background snapshot thread
        self.start_snapshot_worker()
    
    def should_create_snapshot(self):
        """Check if it's time for a snapshot"""
        return time.time() - self.last_snapshot_time > self.snapshot_interval
    
    def create_snapshot(self, cache_data):
        """
        Create snapshot using fork() to avoid blocking main process
        """
        pid = os.fork()
        
        if pid == 0:
            # Child process - create snapshot
            try:
                self.write_snapshot_to_disk(cache_data)
                os._exit(0)
            except Exception as e:
                print(f"Snapshot failed: {e}")
                os._exit(1)
        else:
            # Parent process - continue serving requests
            self.last_snapshot_time = time.time()
            return pid
    
    def write_snapshot_to_disk(self, cache_data):
        """
        Write binary snapshot to disk
        
        Format:
        [MAGIC][VERSION][METADATA][KEY_VALUE_PAIRS][CHECKSUM]
        """
        with open(self.temp_snapshot_path, 'wb') as f:
            # Write header
            f.write(b'REDIS')  # Magic string
            f.write(b'0009')   # Version
            
            # Write metadata
            metadata = {
                'created_at': time.time(),
                'num_keys': len(cache_data),
                'redis_version': '7.0.0'
            }
            self.write_metadata(f, metadata)
            
            # Write key-value pairs
            for key, value_obj in cache_data.items():
                self.write_key_value_pair(f, key, value_obj)
            
            # Write checksum
            checksum = self.calculate_checksum(cache_data)
            f.write(checksum.to_bytes(8, 'little'))
        
        # Atomic rename
        os.rename(self.temp_snapshot_path, self.snapshot_path)
    
    def write_key_value_pair(self, file, key, value_obj):
        """
        Write single key-value pair with type information
        
        Format: [TYPE][EXPIRY][KEY_LEN][KEY][VALUE_LEN][VALUE]
        """
        # Type byte (string, list, hash, set, zset)
        file.write(value_obj['type'].to_bytes(1, 'little'))
        
        # Expiry (0 if no expiry)
        expiry = value_obj.get('expiry', 0)
        file.write(int(expiry).to_bytes(8, 'little'))
        
        # Key
        key_bytes = key.encode('utf-8')
        file.write(len(key_bytes).to_bytes(4, 'little'))
        file.write(key_bytes)
        
        # Value (encoding depends on type)
        value_bytes = self.encode_value(value_obj)
        file.write(len(value_bytes).to_bytes(4, 'little'))
        file.write(value_bytes)
    
    def load_snapshot(self):
        """
        Load snapshot from disk into memory
        """
        if not os.path.exists(self.snapshot_path):
            return {}
        
        cache_data = {}
        
        with open(self.snapshot_path, 'rb') as f:
            # Verify magic and version
            magic = f.read(5)
            if magic != b'REDIS':
                raise ValueError("Invalid RDB file")
            
            version = f.read(4)
            
            # Read metadata
            metadata = self.read_metadata(f)
            
            # Read key-value pairs
            for _ in range(metadata['num_keys']):
                key, value_obj = self.read_key_value_pair(f)
                
                # Skip expired keys
                if value_obj.get('expiry', 0) > 0 and value_obj['expiry'] < time.time():
                    continue
                
                cache_data[key] = value_obj
            
            # Verify checksum
            expected_checksum = int.from_bytes(f.read(8), 'little')
            actual_checksum = self.calculate_checksum(cache_data)
            
            if expected_checksum != actual_checksum:
                raise ValueError("Checksum mismatch - corrupted snapshot")
        
        return cache_data
    
    def start_snapshot_worker(self):
        def snapshot_worker():
            while True:
                time.sleep(self.snapshot_interval)
                if self.should_create_snapshot():
                    self.create_snapshot(self.get_cache_data())
        
        thread = threading.Thread(target=snapshot_worker, daemon=True)
        thread.start()
```

**RDB Pros:**
- Compact single file - easy to backup/transfer
- Fast restart - load entire dataset at once
- Minimal performance impact - fork() uses copy-on-write
- Good for disaster recovery

**RDB Cons:**
- Data loss window - lose data since last snapshot
- Fork can be expensive with large datasets
- Not suitable for durability-critical applications

### AOF (Append-Only File) - Write-Ahead Log

**Concept**: Log every write operation to disk before executing it.

**Implementation:**
```python
class AOFPersistence:
    def __init__(self, aof_path="/var/lib/cache/appendonly.aof"):
        self.aof_path = aof_path
        self.aof_file = open(aof_path, 'ab', buffering=0)  # Unbuffered
        self.fsync_policy = 'everysec'  # 'always', 'everysec', 'no'
        self.last_fsync_time = time.time()
        self.pending_writes = []
        
        # Start fsync worker for 'everysec' policy
        if self.fsync_policy == 'everysec':
            self.start_fsync_worker()
    
    def log_command(self, command, key, value=None, ttl=None):
        """
        Log write command to AOF
        
        Format: *<num_args>\r\n$<len>\r\n<arg>\r\n...
        (Redis RESP protocol)
        """
        # Build command in RESP format
        parts = [command, key]
        if value is not None:
            parts.append(value)
        if ttl is not None:
            parts.extend(['EX', str(ttl)])
        
        # Encode as RESP
        resp_command = self.encode_resp(parts)
        
        # Write to AOF
        self.aof_file.write(resp_command)
        
        # Fsync based on policy
        if self.fsync_policy == 'always':
            os.fsync(self.aof_file.fileno())
        elif self.fsync_policy == 'everysec':
            self.pending_writes.append(time.time())
    
    def encode_resp(self, parts):
        """
        Encode command as RESP (Redis Serialization Protocol)
        
        Example: SET key value
        *3\r\n$3\r\nSET\r\n$3\r\nkey\r\n$5\r\nvalue\r\n
        """
        result = f"*{len(parts)}\r\n"
        
        for part in parts:
            part_str = str(part)
            result += f"${len(part_str)}\r\n{part_str}\r\n"
        
        return result.encode('utf-8')
    
    def start_fsync_worker(self):
        """Background thread to fsync every second"""
        def fsync_worker():
            while True:
                time.sleep(1)
                if self.pending_writes:
                    os.fsync(self.aof_file.fileno())
                    self.pending_writes.clear()
                    self.last_fsync_time = time.time()
        
        thread = threading.Thread(target=fsync_worker, daemon=True)
        thread.start()
    
    def replay_aof(self):
        """
        Replay AOF to rebuild cache state
        """
        if not os.path.exists(self.aof_path):
            return {}
        
        cache_data = {}
        
        with open(self.aof_path, 'rb') as f:
            while True:
                command = self.read_resp_command(f)
                if not command:
                    break
                
                # Execute command to rebuild state
                self.execute_command(cache_data, command)
        
        return cache_data
    
    def read_resp_command(self, file):
        """
        Read single RESP command from file
        """
        line = file.readline()
        if not line:
            return None
        
        # Parse array length
        if not line.startswith(b'*'):
            return None
        
        num_parts = int(line[1:].strip())
        parts = []
        
        for _ in range(num_parts):
            # Read bulk string length
            length_line = file.readline()
            if not length_line.startswith(b'$'):
                return None
            
            length = int(length_line[1:].strip())
            
            # Read bulk string data
            data = file.read(length)
            file.read(2)  # Read \r\n
            
            parts.append(data.decode('utf-8'))
        
        return parts
    
    def execute_command(self, cache_data, command):
        """
        Execute command to rebuild cache state
        """
        cmd = command[0].upper()
        
        if cmd == 'SET':
            key = command[1]
            value = command[2]
            ttl = None
            
            if len(command) > 3 and command[3] == 'EX':
                ttl = int(command[4])
            
            cache_data[key] = {
                'value': value,
                'expiry': time.time() + ttl if ttl else 0
            }
        
        elif cmd == 'DEL':
            key = command[1]
            cache_data.pop(key, None)
        
        elif cmd == 'EXPIRE':
            key = command[1]
            ttl = int(command[2])
            if key in cache_data:
                cache_data[key]['expiry'] = time.time() + ttl
        
        # Add more commands as needed
    
    def rewrite_aof(self, cache_data):
        """
        Rewrite AOF to compact it (remove redundant operations)
        
        Background process that creates new AOF with current state
        """
        temp_aof_path = self.aof_path + ".tmp"
        
        with open(temp_aof_path, 'wb') as f:
            for key, value_obj in cache_data.items():
                # Write SET command for each key
                command = ['SET', key, value_obj['value']]
                
                if value_obj.get('expiry', 0) > 0:
                    ttl = int(value_obj['expiry'] - time.time())
                    if ttl > 0:
                        command.extend(['EX', str(ttl)])
                
                resp_command = self.encode_resp(command)
                f.write(resp_command)
        
        # Atomic rename
        os.rename(temp_aof_path, self.aof_path)
        
        # Reopen file handle
        self.aof_file.close()
        self.aof_file = open(self.aof_path, 'ab', buffering=0)
```

**AOF Fsync Policies:**

1. **always**: Fsync after every write
   - Maximum durability (no data loss)
   - Slowest (disk I/O on every write)
   - ~1000 writes/sec

2. **everysec**: Fsync every second
   - Good balance (lose max 1 second of data)
   - Fast (async fsync)
   - ~50,000 writes/sec

3. **no**: Let OS decide when to fsync
   - Fastest (no explicit fsync)
   - Least durable (lose up to 30 seconds)
   - ~100,000 writes/sec

**AOF Rewrite:**
```python
class AOFRewriter:
    def __init__(self, aof_persistence):
        self.aof = aof_persistence
        self.rewrite_threshold_percentage = 100  # Rewrite when 100% larger
        self.min_size_for_rewrite = 64 * 1024 * 1024  # 64MB
    
    def should_rewrite(self):
        """Check if AOF needs rewriting"""
        current_size = os.path.getsize(self.aof.aof_path)
        
        if current_size < self.min_size_for_rewrite:
            return False
        
        # Estimate size after rewrite (one SET per key)
        estimated_rewritten_size = self.estimate_rewritten_size()
        
        growth_percentage = ((current_size - estimated_rewritten_size) / 
                           estimated_rewritten_size * 100)
        
        return growth_percentage > self.rewrite_threshold_percentage
    
    def background_rewrite(self, cache_data):
        """Fork and rewrite AOF in background"""
        pid = os.fork()
        
        if pid == 0:
            # Child process
            try:
                self.aof.rewrite_aof(cache_data)
                os._exit(0)
            except Exception as e:
                print(f"AOF rewrite failed: {e}")
                os._exit(1)
        else:
            # Parent continues serving requests
            # New writes go to both old and new AOF during rewrite
            return pid
```

### Hybrid Persistence (RDB + AOF)

**Best of both worlds:**
```python
class HybridPersistence:
    def __init__(self):
        self.rdb = RDBPersistence(snapshot_interval=3600)  # Hourly snapshots
        self.aof = AOFPersistence()
        self.aof.fsync_policy = 'everysec'
    
    def persist_write(self, command, key, value=None, ttl=None):
        """Log write to AOF"""
        self.aof.log_command(command, key, value, ttl)
    
    def create_snapshot(self, cache_data):
        """Create RDB snapshot"""
        self.rdb.create_snapshot(cache_data)
    
    def load_data(self):
        """
        Load data on startup:
        1. Load RDB snapshot (fast, bulk load)
        2. Replay AOF from snapshot time (recent changes)
        """
        # Load RDB snapshot
        cache_data = self.rdb.load_snapshot()
        snapshot_time = self.rdb.last_snapshot_time
        
        # Replay AOF commands after snapshot
        aof_data = self.aof.replay_aof_from_time(snapshot_time)
        cache_data.update(aof_data)
        
        return cache_data
    
    def get_recovery_time(self):
        """Estimate recovery time"""
        rdb_size = os.path.getsize(self.rdb.snapshot_path)
        aof_size = os.path.getsize(self.aof.aof_path)
        
        # RDB loads at ~100 MB/s, AOF replays at ~50k ops/s
        rdb_time = rdb_size / (100 * 1024 * 1024)
        aof_ops = aof_size / 100  # Assume 100 bytes per operation
        aof_time = aof_ops / 50000
        
        return rdb_time + aof_time
```

**Persistence Strategy Comparison:**

| Strategy | Durability | Performance | Recovery Time | Disk Usage |
|----------|-----------|-------------|---------------|------------|
| RDB only | Low (5-15 min loss) | High | Fast (seconds) | Low |
| AOF (always) | High (no loss) | Low | Slow (minutes) | High |
| AOF (everysec) | Medium (1 sec loss) | Medium | Slow (minutes) | High |
| Hybrid | Medium (1 sec loss) | Medium | Fast (seconds) | Medium |

**Our Choice: Hybrid with AOF everysec**
- Acceptable data loss (1 second)
- Good write performance (50k ops/sec)
- Fast recovery (RDB + recent AOF)
- Reasonable disk usage

## Summary

Our memory management and persistence strategy provides:

1. **Efficient Memory Usage**: Optimized encodings and data structures
2. **Smart Eviction**: Multiple policies adapted to workload patterns  
3. **Fragmentation Control**: Active defragmentation to reclaim wasted memory
4. **Pressure Monitoring**: Proactive memory management before OOM
5. **Performance Optimization**: Bloom filters and compressed structures
6. **Durable Persistence**: Hybrid RDB+AOF for fast recovery with minimal data loss
7. **Flexible Fsync Policies**: Balance between durability and performance

The combination of approximate LRU eviction, active TTL expiration, memory optimization techniques, and hybrid persistence ensures our distributed cache maintains high performance even under memory pressure while providing durability guarantees.

Next, we'll design the failure handling and recovery mechanisms that keep the system running during various failure scenarios.