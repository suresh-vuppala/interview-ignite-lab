Rotate a linked list to the right by k places.

<br>

> Example: 1→2→3→4→5, k=2 → 4→5→1→2→3
> **Key insight:** Connect tail to head (make circular). Find new tail at position (len - k%len - 1). Break there.

<br>

---

## Constraints
- `0 ≤ N ≤ 5 × 10⁴`

<br>

---

## Solution 1: Rotate one position K times

**Intuition:**
The most straightforward approach — rotating one position at a time is o(n) per rotation.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N×K)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Rotating one position at a time is O(N) per rotation. Circular list technique is O(N) total.

> **Key Insight for Improvement:**
> Use Optimal for O(N) time.

<br>

---

## Solution 2: Optimal

**Algorithm:**
1. Find length and tail
2. k = k%len
3. tail.next = head (circular)
4. Traverse to (len-k-1)th node = new tail
5. new head = newTail.next, newTail.next = null

### Time Complexity: O(N)
**Why?** Single pass (or two passes) through the list. O(1) work per node.

**Detailed breakdown:** N = 50,000 → ~100,000 operations max

### Space Complexity: O(1)

> **Drawback:** None — O(N) time, O(1) space is optimal for linked list operations.

> **Key Insight for Improvement:** Already optimal. These structural transformations are classic interview patterns that combine multiple linked list techniques.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Optimal | O(N) | O(1) |

**Key Insights:**
1. **Combines multiple techniques:** Middle-finding, reversal, merging, partitioning
2. **Pointer manipulation:** Careful rewiring without extra space
3. **Dummy nodes:** Simplify edge cases throughout

<br><br>

---

```code```
