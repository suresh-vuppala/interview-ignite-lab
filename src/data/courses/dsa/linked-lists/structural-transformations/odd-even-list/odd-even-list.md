Group odd-indexed nodes before even-indexed nodes.

<br>

> Example: 1→2→3→4→5 → 1→3→5→2→4
> **Key insight:** Two pointers: odd and even. Odd collects odd-indexed, even collects even-indexed. Connect odd tail to even head.

<br>

---

## Constraints
- `0 ≤ N ≤ 5 × 10⁴`

<br>

---

## Solution 1: Create two new lists, concatenate

**Intuition:**
The most straightforward approach — extra space for two new lists.

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
> Extra space for two new lists. Can be done in-place by rewiring pointers.

> **Key Insight for Improvement:**
> Use Optimal for O(N) time.

<br>

---

## Solution 2: Optimal

**Algorithm:**
odd=head, even=head.next, evenHead=even. While even and even.next: odd.next=even.next, odd=odd.next, even.next=odd.next, even=even.next. odd.next=evenHead.

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
