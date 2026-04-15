Delete a given node from a doubly linked list in O(1) time.

<br>

> Example: Delete node 3 from 1↔2↔3↔4 → 1↔2↔4
> **Key insight:** With doubly linked list, we have direct access to both predecessor and successor. Rewire: prev.next = target.next, target.next.prev = target.prev. O(1)!

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

## All Possible Edge Cases
1. **Delete only node**
2. **Delete head / tail**
3. **Node not found**
4. **Verify prev/next after deletion**

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use Direct Pointer Rewiring (Optimal) for O(1) given node reference time.

<br>

---

## Solution 2: Direct Pointer Rewiring (Optimal)

### Time Complexity: O(1) given node reference
### Space Complexity: O(1)

> **Drawback:** None — this is the KEY advantage of doubly linked lists over singly.

> **Key Insight for Improvement:** O(1) deletion is why DLL is used in LRU Cache alongside a hash map. Singly LL deletion given a node is O(N) (need predecessor).

<br>

---

**Key Insights:**
1. **O(1) deletion:** The main advantage over singly linked list
2. **Handle head/tail:** Check if target is head or tail, update accordingly
3. **Used in:** LRU Cache, LFU Cache — O(1) eviction

<br><br>

---

```code```
