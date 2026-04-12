Insert a new interval into sorted non-overlapping intervals, merge if needed.

<br>

> **Key insight:** Find position, merge overlapping intervals on both sides.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Linear scan: skip before, merge overlapping, add after

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Linear scan: skip before, merge overlapping, add after`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
