Delete a node by value from a circular linked list.

<br>

> Example: Delete 2 from circular 1→2→3→(back to 1) → 1→3→(back to 1)
> **Key insight:** Find predecessor of target node. Rewire: prev.next = target.next. Special case: deleting head requires updating the circular link.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

## All Possible Edge Cases
1. **Delete only node → empty list**
2. **Delete head node**
3. **Node not in list**

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
> Use Find Predecessor + Rewire (Optimal) for O(N) time.

<br>

---

## Solution 2: Find Predecessor + Rewire (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** Must handle head deletion specially — update the tail's next pointer.

> **Key Insight for Improvement:** Single node deletion: if head.next == head → return null (empty list).

<br>

---

**Key Insights:**
1. **Head deletion:** Find tail first, then tail.next = head.next, return head.next
2. **Single node:** head.next == head → return null
3. **Standard deletion:** Same as singly LL but with circular termination check

<br><br>

---

```code```
