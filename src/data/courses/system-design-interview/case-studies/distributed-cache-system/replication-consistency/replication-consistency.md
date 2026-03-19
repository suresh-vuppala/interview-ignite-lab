## Why Replication is Critical

Replication serves multiple purposes in distributed caches:

1. **High Availability**: System continues working when nodes fail
2. **Fault Tolerance**: Data survives hardware failures
3. **Read Scalability**: Distribute read load across replicas
4. **Geographic Distribution**: Serve users from nearby locations
5. **Disaster Recovery**: Recover from data center outages

## Replication Strategies

### 1. Master-Slave Replication

**Architecture:**
- One primary (master) node per shard handles all writes
- Multiple replica (slave) nodes receive updates from primary
- Reads can be served from primary or replicas

```
Primary Node A
    ├── Replica A1 (async replication)
    ├── Replica A2 (async replication)
    └── Replica A3 (async replication)

Write Flow:
Client → Primary → [Async] → Replicas

Read Flow:
Client → Primary OR Replica
```

**Pros:**
- Simple to understand and implement
- Strong consistency for writes (single writer)
- Good read scalability
- Clear data ownership

**Cons:**
- Single point of failure for writes
- Primary can become bottleneck
- Replica lag during high write load

### 2. Master-Master Replication

**Architecture:**
- Multiple nodes can accept writes for the same data
- Changes propagate to all other masters
- Requires conflict resolution

**Pros:**
- No single point of failure for writes
- Better write scalability
- Geographic distribution of writes

**Cons:**
- Complex conflict resolution
- Eventual consistency only
- Risk of data conflicts
- More complex to operate

**Verdict:** ❌ Too complex for cache use cases

### 3. Quorum-Based Replication

**Architecture:**
- Writes must be acknowledged by W replicas
- Reads must query R replicas
- If W + R > N, strong consistency guaranteed

**Example with N=3, W=2, R=2:**
```
Write: Must succeed on 2 out of 3 replicas
Read: Must query 2 out of 3 replicas
Guarantee: At least 1 replica has latest data
```

**Pros:**
- Tunable consistency vs availability
- Survives minority node failures
- No single master bottleneck

**Cons:**
- Higher latency (wait for multiple nodes)
- More complex client logic
- Partial failures are complex

**Verdict:** ⚠️ Consider for critical data, overkill for cache

## Chosen Approach: Async Master-Slave

For our distributed cache, we choose **async master-slave replication**:

### Replication Architecture

```
Shard 1:
  Primary-1 (writes + reads)
    ├── Replica-1a (reads only)
    └── Replica-1b (reads only)

Shard 2:
  Primary-2 (writes + reads)
    ├── Replica-2a (reads only)
    └── Replica-2b (reads only)

Replication Flow:
1. Client writes to Primary-1
2. Primary-1 acknowledges immediately
3. Primary-1 async replicates to Replica-1a, Replica-1b
4. Replicas apply changes and update replication offset
```

### Replication Protocol

```python
class ReplicationMaster:
    def __init__(self):
        self.replicas = []
        self.replication_offset = 0
        self.replication_backlog = CircularBuffer(size=64*1024*1024)  # 64MB
    
    def execute_write(self, command, *args):
        # Execute on master
        result = self.storage.execute(command, *args)
        
        # Add to replication log
        self.replication_offset += 1
        repl_entry = {
            'offset': self.replication_offset,
            'command': command,
            'args': args,
            'timestamp': time.time()
        }
        self.replication_backlog.append(repl_entry)
        
        # Async replicate to slaves
        self.replicate_async(repl_entry)
        
        return result
    
    def replicate_async(self, entry):
        for replica in self.replicas:
            # Non-blocking send
            replica.send_async(entry)

class ReplicationSlave:
    def __init__(self, master_host, master_port):
        self.master_offset = 0
        self.connection = Connection(master_host, master_port)
        self.start_replication()
    
    def start_replication(self):
        # Send PSYNC command to master
        self.connection.send(f"PSYNC {self.master_offset}")
        
        # Receive replication stream
        while True:
            entry = self.connection.receive()
            self.apply_replication_entry(entry)
    
    def apply_replication_entry(self, entry):
        # Apply command to local storage
        self.storage.execute(entry['command'], *entry['args'])
        self.master_offset = entry['offset']
```

## Consistency Models

### 1. Eventual Consistency (Default)

**Behavior:**
- Writes return immediately after primary acknowledges
- Replicas eventually receive and apply updates
- Temporary inconsistency between primary and replicas

**Use Cases:**
- Cache data (source of truth is database)
- Session storage (brief inconsistency acceptable)
- Counters where approximate values are okay

```python
# Client code - eventual consistency
cache.set("user:123:profile", profile_data)  # Returns immediately
# Replicas may not have this data yet

profile = cache.get("user:123:profile")  # Might read from replica
# Could return old data or None if replica is behind
```

### 2. Read-Your-Writes Consistency

**Behavior:**
- After writing, subsequent reads see the written value
- Achieved by routing reads to primary after writes
- Or by tracking write timestamps

**Implementation:**
```python
class ReadYourWritesClient:
    def __init__(self):
        self.last_write_time = {}  # key → timestamp
        self.write_timeout = 1.0   # 1 second
    
    def set(self, key, value):
        result = self.primary.set(key, value)
        self.last_write_time[key] = time.time()
        return result
    
    def get(self, key):
        # Check if we recently wrote this key
        if key in self.last_write_time:
            time_since_write = time.time() - self.last_write_time[key]
            if time_since_write < self.write_timeout:
                # Read from primary to ensure consistency
                return self.primary.get(key)
        
        # Safe to read from replica
        return self.replica.get(key)
```

### 3. Strong Consistency

**Behavior:**
- All reads see the most recent write
- Achieved through synchronous replication or primary-only reads

**Implementation:**
```python
class StrongConsistencyClient:
    def __init__(self):
        self.primary_only = True  # All reads go to primary
    
    def get(self, key):
        # Always read from primary for strong consistency
        return self.primary.get(key)
    
    def set(self, key, value):
        # Synchronous replication (optional)
        if self.sync_replication:
            return self.primary.set_sync(key, value)
        else:
            return self.primary.set(key, value)
```

## Failover and Recovery

### Failure Detection

```python
class FailureDetector:
    def __init__(self):
        self.node_status = {}  # node_id → status
        self.heartbeat_interval = 1.0  # 1 second
        self.failure_threshold = 5.0   # 5 seconds
    
    def start_monitoring(self):
        while True:
            for node in self.cluster_nodes:
                try:
                    response = node.ping(timeout=0.5)
                    self.node_status[node.id] = {
                        'status': 'healthy',
                        'last_seen': time.time()
                    }
                except TimeoutError:
                    self.handle_node_timeout(node)
            
            time.sleep(self.heartbeat_interval)
    
    def handle_node_timeout(self, node):
        last_seen = self.node_status.get(node.id, {}).get('last_seen', 0)
        time_since_seen = time.time() - last_seen
        
        if time_since_seen > self.failure_threshold:
            self.mark_node_failed(node)
    
    def mark_node_failed(self, node):
        self.node_status[node.id]['status'] = 'failed'
        self.trigger_failover(node)
```

### Automatic Failover

```python
class FailoverManager:
    def trigger_failover(self, failed_primary):
        # 1. Find best replica to promote
        best_replica = self.select_best_replica(failed_primary)
        
        # 2. Promote replica to primary
        self.promote_replica(best_replica, failed_primary)
        
        # 3. Update cluster topology
        self.update_cluster_topology(failed_primary, best_replica)
        
        # 4. Notify clients of topology change
        self.notify_topology_change()
    
    def select_best_replica(self, failed_primary):
        replicas = self.get_replicas(failed_primary)
        
        # Choose replica with highest replication offset (least lag)
        best_replica = max(replicas, key=lambda r: r.replication_offset)
        
        return best_replica
    
    def promote_replica(self, replica, old_primary):
        # Stop replication from old primary
        replica.stop_replication()
        
        # Enable writes on replica
        replica.enable_writes()
        
        # Start accepting replication connections
        replica.start_replication_server()
        
        # Update other replicas to replicate from new primary
        for other_replica in self.get_other_replicas(old_primary, replica):
            other_replica.change_master(replica.host, replica.port)
```

### Split-Brain Prevention

**Problem:**
Network partition isolates primary from cluster, but primary can still serve clients.
Replica gets promoted to new primary. Now we have two primaries accepting writes.

**Solution 1: Quorum-Based Decisions**
```python
class QuorumFailover:
    def can_accept_writes(self, node):
        # Node can only accept writes if it can reach majority of cluster
        reachable_nodes = self.count_reachable_nodes(node)
        total_nodes = len(self.cluster_nodes)
        
        return reachable_nodes > total_nodes // 2
    
    def handle_write_request(self, node, request):
        if not self.can_accept_writes(node):
            raise ClusterDownException("Cannot reach quorum")
        
        return node.execute_write(request)
```

**Solution 2: Fencing Tokens**
```python
class FencingTokenManager:
    def __init__(self):
        self.current_epoch = 0
    
    def promote_primary(self, new_primary):
        # Increment epoch and assign to new primary
        self.current_epoch += 1
        new_primary.set_epoch(self.current_epoch)
        
        # Invalidate old primary's epoch
        self.broadcast_epoch_update(self.current_epoch)
    
    def validate_write(self, node, epoch, request):
        if epoch < self.current_epoch:
            raise FencedWriteException("Stale epoch, write rejected")
        
        return node.execute_write(request)
```

## Replication Lag Management

### Monitoring Replication Lag

```python
class ReplicationMonitor:
    def __init__(self):
        self.lag_thresholds = {
            'warning': 1000,    # 1000 operations behind
            'critical': 10000   # 10000 operations behind
        }
    
    def check_replication_lag(self):
        for primary in self.primaries:
            primary_offset = primary.get_replication_offset()
            
            for replica in primary.replicas:
                replica_offset = replica.get_replication_offset()
                lag = primary_offset - replica_offset
                
                if lag > self.lag_thresholds['critical']:
                    self.alert_critical_lag(primary, replica, lag)
                elif lag > self.lag_thresholds['warning']:
                    self.alert_warning_lag(primary, replica, lag)
    
    def alert_critical_lag(self, primary, replica, lag):
        # Critical lag - consider removing replica from read pool
        self.remove_from_read_pool(replica)
        self.send_alert(f"Critical replication lag: {lag} operations")
    
    def remove_from_read_pool(self, replica):
        # Stop routing reads to lagging replica
        self.load_balancer.remove_replica(replica)
```

### Handling Slow Replicas

```python
class ReplicationBackpressure:
    def __init__(self):
        self.max_replication_lag = 5000
        self.slow_replica_threshold = 2000
    
    def handle_slow_replica(self, primary, slow_replica):
        # Option 1: Throttle writes to primary
        if self.should_throttle_writes(primary):
            primary.enable_write_throttling()
        
        # Option 2: Remove slow replica temporarily
        if self.should_remove_replica(slow_replica):
            self.temporarily_remove_replica(slow_replica)
        
        # Option 3: Trigger full resync
        if self.should_resync(slow_replica):
            slow_replica.trigger_full_resync()
    
    def should_throttle_writes(self, primary):
        avg_lag = self.calculate_average_lag(primary.replicas)
        return avg_lag > self.slow_replica_threshold
    
    def should_remove_replica(self, replica):
        lag = self.get_replication_lag(replica)
        return lag > self.max_replication_lag
```

## Cross-Region Replication

### Architecture for Global Distribution

```
Region 1 (US-East):
  Primary-1A, Replica-1B, Replica-1C

Region 2 (EU-West):
  Replica-1D (async from Primary-1A)

Region 3 (Asia-Pacific):
  Replica-1E (async from Primary-1A)

Cross-region replication:
- Higher latency (50-200ms)
- Potential for higher lag
- Network partition tolerance needed
```

### Implementation

```python
class CrossRegionReplication:
    def __init__(self):
        self.regions = {
            'us-east': {'primary': True, 'replicas': ['us-east-1b', 'us-east-1c']},
            'eu-west': {'primary': False, 'replicas': ['eu-west-1a']},
            'ap-southeast': {'primary': False, 'replicas': ['ap-southeast-1a']}
        }
    
    def setup_cross_region_replication(self):
        primary_region = self.get_primary_region()
        
        for region_name, config in self.regions.items():
            if not config['primary']:
                # Setup cross-region replica
                replica = self.create_cross_region_replica(
                    region_name, 
                    primary_region
                )
                self.configure_replication_stream(replica, primary_region)
    
    def handle_cross_region_lag(self, replica, lag_ms):
        if lag_ms > 5000:  # 5 second lag
            # Consider local caching or read-through patterns
            self.enable_local_caching(replica.region)
        
        if lag_ms > 30000:  # 30 second lag
            # Network issues - consider failover
            self.consider_regional_failover(replica.region)
```

## Consistency Trade-offs Summary

| Consistency Level | Latency | Availability | Use Cases |
|------------------|---------|--------------|-----------|
| **Eventual** | Lowest | Highest | Cache, sessions, counters |
| **Read-Your-Writes** | Medium | High | User profiles, settings |
| **Strong** | Highest | Lower | Financial data, inventory |

## Monitoring and Alerting

### Key Metrics

```python
class ReplicationMetrics:
    def collect_metrics(self):
        return {
            'replication_lag_seconds': self.get_max_replication_lag(),
            'replica_count': len(self.active_replicas),
            'failed_replicas': len(self.failed_replicas),
            'cross_region_lag_ms': self.get_cross_region_lag(),
            'failover_count_24h': self.get_recent_failovers(),
            'split_brain_incidents': self.get_split_brain_count()
        }
    
    def get_alert_conditions(self):
        return {
            'replication_lag_seconds > 10': 'CRITICAL',
            'failed_replicas > 1': 'WARNING',
            'cross_region_lag_ms > 30000': 'WARNING',
            'failover_count_24h > 3': 'CRITICAL',
            'split_brain_incidents > 0': 'CRITICAL'
        }
```

## Summary

Our replication strategy provides:

1. **High Availability**: Async master-slave with automatic failover
2. **Tunable Consistency**: From eventual to strong consistency
3. **Split-Brain Prevention**: Quorum-based decisions and fencing tokens
4. **Global Distribution**: Cross-region replication for worldwide access
5. **Comprehensive Monitoring**: Track lag, failures, and performance

The async replication model prioritizes performance and availability while providing sufficient consistency guarantees for cache use cases. The automatic failover ensures minimal downtime during node failures.

Next, we'll design the memory management and eviction policies that keep our cache performant under memory pressure.