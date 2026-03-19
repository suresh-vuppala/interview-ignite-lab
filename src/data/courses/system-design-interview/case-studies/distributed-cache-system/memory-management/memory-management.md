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

## Summary

Our memory management strategy provides:

1. **Efficient Memory Usage**: Optimized encodings and data structures
2. **Smart Eviction**: Multiple policies adapted to workload patterns  
3. **Fragmentation Control**: Active defragmentation to reclaim wasted memory
4. **Pressure Monitoring**: Proactive memory management before OOM
5. **Performance Optimization**: Bloom filters and compressed structures

The combination of approximate LRU eviction, active TTL expiration, and memory optimization techniques ensures our distributed cache maintains high performance even under memory pressure.

Next, we'll design the failure handling and recovery mechanisms that keep the system running during various failure scenarios.