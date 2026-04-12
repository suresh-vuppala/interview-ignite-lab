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

## Solution: Optimal

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
