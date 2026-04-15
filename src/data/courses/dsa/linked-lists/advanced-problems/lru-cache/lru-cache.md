Design a Least Recently Used (LRU) cache. O(1) for get and put. When capacity exceeded, evict the least recently used item.

<br>

> Input: capacity=2, put(1,1), put(2,2), get(1)→1, put(3,3), get(2)→-1 (evicted)
> **Key insight:** Hash map (O(1) lookup) + Doubly linked list (O(1) remove/insert). Most recently used at head, least recently used at tail. On access: move to head. On eviction: remove tail.

<br>

---

## Constraints
- `1 ≤ capacity ≤ 3000`

<br>

---

## All Possible Edge Cases
1. **Get non-existent key:** return -1
2. **Put when cache full:** evict LRU
3. **Access existing key updates recency
4. **Capacity = 1**

<br>

---

## Solution 1: Array + linear search for LRU

**Intuition:**
The most straightforward approach — linear scan to find and evict lru item.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) per get/put
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Linear scan to find and evict LRU item. HashMap + DLL achieves O(1).

> **Key Insight for Improvement:**
> Use Hash Map + Doubly Linked List (Optimal) for O(1) per operation time.

<br>

---

## Solution 2: Hash Map + Doubly Linked List (Optimal)

**Algorithm:**
- get(key): if in map → move node to head, return value. Else -1.
- put(key, value): if in map → update value, move to head. Else create node, add to head, add to map. If over capacity → remove tail, remove from map.

### Time Complexity: O(1) per operation
**Why?** Hash map: O(1) lookup. DLL: O(1) insert/remove at head/tail.

**Detailed breakdown:** 3000 capacity → O(1) per get/put regardless

### Space Complexity: O(capacity)

> **Drawback:** Doubly linked list + hash map is complex to implement correctly. But it's the only way to achieve O(1) for all operations.

> **Key Insight for Improvement:** Sentinel nodes (dummy head and tail) simplify edge cases — no null checks for first/last element.

<br>

---

## Complexity Progression Summary

| Solution | get | put | Space |
|----------|-----|-----|-------|
| Array scan | O(N) | O(N) | O(N) |
| OrderedDict (Python) | O(1) | O(1) | O(N) |
| HashMap + DLL | O(1) | O(1) | O(N) |

**Key Insights:**
1. **HashMap + DLL = O(1) everything:** The classic data structure design pattern
2. **Sentinel nodes:** Dummy head and tail eliminate all null checks
3. **Move to head on access:** Maintains recency ordering
4. **FAANG top-3 design:** Asked at Google, Amazon, Meta, Microsoft

<br><br>

---

```code```
