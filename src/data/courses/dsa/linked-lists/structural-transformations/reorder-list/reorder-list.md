Reorder L0→L1→...→Ln to L0→Ln→L1→Ln-1→...

<br>

> Example: 1→2→3→4→5 → 1→5→2→4→3
> **Key insight:** Find middle, reverse second half, merge alternating (interleave).

<br>

---

## Constraints
- `0 ≤ N ≤ 5 × 10⁴`

<br>

---

## All Possible Edge Cases
1. **0-2 nodes:** no reordering needed
2. **Odd vs even length**
3. **Already in correct order**

<br>

---

## Solution 1: Copy to array, two-pointer reorder

**Intuition:**
The most straightforward approach — array copy uses o(n) extra space.

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
> Array copy uses O(N) extra space. In-place: find middle + reverse + merge.

> **Key Insight for Improvement:**
> Use Optimal for O(N) time.

<br>

---

## Solution 2: Optimal

**Algorithm:**
1. Find middle (slow/fast)
2. Reverse second half
3. Interleave: take from first, then from reversed second, alternating

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
