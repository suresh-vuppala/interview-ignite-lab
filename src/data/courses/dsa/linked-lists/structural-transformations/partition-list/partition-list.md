Partition list around value x: all nodes < x come before nodes ≥ x.

<br>

> Example: 1→4→3→2→5→2, x=3 → 1→2→2→4→3→5
> **Key insight:** Two dummy lists: 'before' (< x) and 'after' (≥ x). Scan original, append to appropriate list. Connect before-tail to after-head.

<br>

---

## Constraints
- `0 ≤ N ≤ 5 × 10⁴`

<br>

---

## Solution: Optimal

**Algorithm:**
Dummy before, dummy after. For each node: if val < x → append to before, else → append to after. Connect. Set after-tail.next = null.

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
