# Design a Cache System (LRU, LFU)

Design a flexible in-memory cache supporting multiple eviction policies: LRU (Least Recently Used) and LFU (Least Frequently Used).

<br>

---

## Requirements

### Main Requirements
1. **get(key)** — return value if exists, else -1
2. **put(key, value)** — insert or update, evict if at capacity
3. **Eviction policies** — LRU, LFU (swappable via Strategy)
4. **O(1) operations** — both get and put must be O(1)
5. **TTL support** — optional expiration time per entry
6. **Thread-safe** — concurrent access

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Strategy** | EvictionPolicy (LRU, LFU) | Swappable eviction logic |
| **Proxy** | CacheProxy for logging, metrics | Add cross-cutting concerns |

<br>

---

## Data Structures

### LRU: HashMap + Doubly Linked List
- HashMap: O(1) lookup
- DLL: maintains access order, O(1) move-to-front

### LFU: HashMap + Frequency Map + DLL per frequency
- HashMap: key → node
- FreqMap: frequency → DLL of nodes
- minFreq tracker for O(1) eviction

<br>

---

## Interview Tips

- LRU is the most commonly asked cache design
- Key insight: HashMap gives O(1) lookup, DLL gives O(1) reordering
- Java shortcut: `LinkedHashMap(capacity, 0.75f, true)` with `removeEldestEntry`
- LFU is harder — explain the frequency-bucketed DLL approach
- Discuss: distributed cache (Redis), cache-aside vs write-through vs write-back
