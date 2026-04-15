# Design a Cache System (LRU, LFU)

Design a flexible in-memory cache supporting multiple eviction policies with O(1) operations.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **get(key)** — return value if exists, else -1 (or null)
2. **put(key, value)** — insert or update; evict if at capacity
3. **Eviction policies** — LRU (Least Recently Used), LFU (Least Frequently Used)
4. **O(1) operations** — both get and put must be constant time
5. **Configurable capacity** — set max entries at creation

### Extended Requirements (If Time Permits)

1. TTL (Time-To-Live) per entry — auto-expire after N seconds
2. Thread-safe — concurrent get/put
3. Cache statistics — hit rate, miss rate, eviction count
4. Distributed cache (across multiple servers)
5. Write-through / write-back / cache-aside strategies
6. LRU + LFU hybrid eviction

<br>

---

## Constraints

- Capacity: 1 to 100,000 entries
- Key type: Integer or String
- Value type: any Object
- get: O(1) time complexity
- put: O(1) time complexity
- Eviction: O(1) for both LRU and LFU
- Memory: O(capacity) total

<br>

---

## Identify Primary Actors

1. **Application** — reads/writes cached data
   - Actions: get(key), put(key, value), invalidate(key)

2. **Eviction Policy** — decides what to remove when cache is full
   - Actions: track access patterns, select victim entry

3. **Cache Manager** — orchestrates cache operations
   - Actions: delegate to eviction policy, maintain capacity

<br>

---

## Core Entities

### 1. Cache (Interface)
- **Methods**: get(key): value, put(key, value), size(), clear()
- **Responsibilities**: Define cache contract

### 2. LRUCache
- **Data Structures**: HashMap<key, DLLNode> + Doubly Linked List
- **Algorithm**: Most recently used at head, least at tail; evict tail
- **get**: Move node to head (O(1) with DLL)
- **put**: Add to head; if over capacity, remove tail (O(1))

### 3. LFUCache
- **Data Structures**: HashMap<key, [value, freq]> + HashMap<freq, LinkedHashSet<key>>
- **Algorithm**: Track access frequency per key; evict lowest frequency (ties → LRU among those)
- **get**: Increment frequency, move to next frequency bucket
- **put**: Insert at freq=1; if over capacity, evict from minFreq bucket

### 4. DLLNode (for LRU)
- **Attributes**: key, value, prev, next
- **Responsibilities**: Doubly-linked list node for O(1) removal/insertion

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| LRUCache | uses | HashMap<key, DLLNode> | Composition (◆) |
| LRUCache | uses | DoublyLinkedList (head, tail sentinels) | Composition (◆) |
| LFUCache | uses | HashMap<key, [value,freq]> | Composition (◆) |
| LFUCache | uses | HashMap<freq, LinkedHashSet<key>> | Composition (◆) |
| LRUCache | implements | Cache | Implementation |
| LFUCache | implements | Cache | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
  <<interface>> Cache<K, V>
  +get(key): V
  +put(key, value): void
       △
  ┌────┴────┐
LRUCache  LFUCache


  LRU Internal Structure:
  ┌─────────────┐
  │ HashMap     │    key → DLLNode reference (O(1) lookup)
  └──────┬──────┘
         │ sync
  ┌──────▼──────┐
  │ Doubly LL   │    HEAD ↔ [MRU] ↔ ... ↔ [LRU] ↔ TAIL
  └─────────────┘    (O(1) add to head, remove from tail)


  LFU Internal Structure:
  ┌─────────────┐
  │ keyMap       │    key → {value, frequency}
  └──────┬──────┘
         │ sync
  ┌──────▼──────┐
  │ freqMap      │    freq → LinkedHashSet<key> (insertion order for LRU tiebreak)
  └─────────────┘    minFreq pointer for O(1) eviction
```

<br>

---

## Design Patterns Used

### 1. **Strategy Pattern**
- **Where**: Cache interface with LRU and LFU implementations
- **Why**: Different eviction policies for different use cases (LRU for general, LFU for frequency-based)
- **Benefit**: Swap eviction policy without changing client code

### 2. **Composite Data Structure**
- **Where**: HashMap + DLL (LRU) or HashMap + FreqMap (LFU)
- **Why**: No single data structure provides both O(1) lookup AND O(1) ordered eviction
- **Benefit**: Combining two structures achieves O(1) for all operations

### 3. **Proxy Pattern** (extended)
- **Where**: CacheProxy wrapping cache for logging, metrics, TTL enforcement
- **Why**: Add cross-cutting concerns without modifying cache internals

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **LRU (simple)**: `synchronized` on get/put — coarse-grained but correct
- **LRU (better)**: `ReadWriteLock` — concurrent gets (read lock), exclusive puts (write lock)
- **Java shortcut**: `Collections.synchronizedMap(new LinkedHashMap(cap, 0.75f, true))`
- **LFU**: Must lock both keyMap and freqMap atomically — `synchronized(this)`

### Race Conditions Handled
- **Concurrent get + put same key**: Lock ensures either operation completes before the other starts
- **Eviction during get**: Put acquires write lock, evicts tail; concurrent get waits
- **Two puts triggering eviction**: Sequential under lock — each eviction is atomic

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Capacity = 0** — all puts are no-ops (or throw)
2. **Capacity = 1** — every new put evicts the previous entry
3. **Get non-existent key** — return -1 or null (not an error)
4. **Put existing key** — update value, refresh access order (move to head for LRU)
5. **LFU tie breaking** — multiple keys with same frequency → evict least recently used among them
6. **Null key or value** — reject with NullPointerException or handle gracefully
7. **Integer overflow in frequency counter** — cap at Integer.MAX_VALUE
8. **All entries same frequency** — LFU degenerates to LRU within that frequency bucket

### Error Handling Strategy
- **NullKeyException**: Reject null keys
- **CapacityExceededException**: Should never happen — eviction prevents it
- **ConcurrentModificationException**: Use proper synchronization to prevent

<br>

---

## LRU vs LFU Comparison

| Aspect | LRU | LFU |
|--------|-----|-----|
| **Evicts** | Least recently accessed | Least frequently accessed |
| **Best for** | Temporal locality (recent = likely needed) | Frequency locality (popular items) |
| **Weakness** | Scan pollution (one-time scan evicts useful items) | Cache pollution (once-hot items never evicted) |
| **Complexity** | HashMap + DLL | HashMap + FreqMap + minFreq |
| **Common use** | General purpose, OS page cache | CDN, database query cache |

<br>

---

## Implementation

```code```
