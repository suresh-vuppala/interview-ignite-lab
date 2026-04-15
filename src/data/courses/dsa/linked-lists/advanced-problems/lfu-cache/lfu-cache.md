Design a Least Frequently Used (LFU) cache. O(1) for get and put. When capacity exceeded, evict the least frequently used item (ties broken by least recently used).

<br>

> Input: capacity=2, put(1,1), put(2,2), get(1)→1, put(3,3), get(2)→-1
> **Key insight:** Hash map for key→node. Hash map for freq→DLL (ordered by recency). Track minimum frequency. On access: move node from freq list to freq+1 list.

<br>

---

## Constraints
- `0 ≤ capacity ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **Tie in frequency:** evict least recently used
2. **Capacity = 0:** never stores
3. **Same key updated multiple times
4. **Get increments frequency**

<br>

---

## Solution 1: Array + frequency counter

**Intuition:**
The most straightforward approach — scanning for minimum frequency is o(n).

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
> Scanning for minimum frequency is O(N). Two hashmaps + DLL per freq = O(1).

> **Key Insight for Improvement:**
> Use Two Hash Maps + DLLs (Optimal) for O(1) per operation time.

<br>

---

## Solution 2: Two Hash Maps + DLLs (Optimal)

**Algorithm:**
- get: lookup in map, increase frequency, move to new freq list, return value
- put: if exists → update + get logic. New → add at freq=1. If over capacity → evict from min_freq list's tail.

### Time Complexity: O(1) per operation
**Why?** All operations are hash map lookups + DLL insert/remove.

### Space Complexity: O(capacity)

> **Drawback:** More complex than LRU. Three data structures to maintain.

> **Key Insight for Improvement:** Track min_freq: on new insert, min_freq = 1. When min_freq list becomes empty, min_freq++. This avoids scanning for the minimum.

<br>

---

## Complexity Progression Summary

| Cache | get | put | Eviction Policy |
|-------|-----|-----|----------------|
| LRU | O(1) | O(1) | Least recently used |
| LFU | O(1) | O(1) | Least frequently used (LRU for ties) |

**Key Insights:**
1. **freq→DLL map:** Each frequency has its own recency-ordered list
2. **min_freq tracking:** Avoids scanning for minimum frequency
3. **Frequency update:** Remove from old freq list, add to freq+1 list

<br><br>

---

```code```
