Find median from a data stream efficiently.

<br>

> **Key insight:** Two heaps: max-heap for lower half, min-heap for upper half. Balance sizes. Median from tops.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Max-heap (lower) + Min-heap (upper), balance sizes

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Max-heap (lower) + Min-heap (upper), balance sizes`

### Time Complexity: O(log N) per add, O(1) median
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log N) per add, O(1) median | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
