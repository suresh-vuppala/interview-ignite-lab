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

## Solution 1: Copy to array, partition, rebuild

**Intuition:**
The most straightforward approach — extra space.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(N) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Extra space. Two-pointer partition rewires in-place.

> **Key Insight for Improvement:**
> Use Optimal for O(N) time.

<br>

---

## Solution 2: Optimal

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
