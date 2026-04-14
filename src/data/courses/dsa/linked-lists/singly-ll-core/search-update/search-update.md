Search for a value in a linked list and update a node's value.

<br>

> Input: list = 1→2→3, search(2) → true, update(2, 99) → 1→99→3
> **Key insight:** Linear scan — traverse until found or end. No binary search possible (no random access).

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

<br>

---

## Solution 1: N/A for search — linear scan is already optimal

**Intuition:**
The most straightforward approach — linear scan is the only option for unsorted linked list.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Linear scan is the only option for unsorted linked list. No way to binary search without random access.

> **Key Insight for Improvement:**
> Use Linear Scan (Optimal) for O(N) time.

<br>

---

## Solution 2: Linear Scan (Optimal)

### Time Complexity: O(N)
**Why?** Must traverse sequentially — no random access.

### Space Complexity: O(1)

> **Drawback:** O(N) search. No way to do better with a basic linked list.

> **Key Insight for Improvement:** For O(1) access by value, use a hash map alongside the linked list (like LRU Cache does).

<br>

---

## Complexity Progression Summary

| Operation | Linked List | Array | Hash Map + LL |
|-----------|-------------|-------|---------------|
| Search | O(N) | O(N) or O(logN) sorted | O(1) |
| Update by value | O(N) | O(N) | O(1) |

**Key Insights:**
1. **No random access:** Must traverse from head
2. **Hash map augmentation:** LRU cache = hash map + doubly linked list for O(1) ops

<br><br>

---

```code```
