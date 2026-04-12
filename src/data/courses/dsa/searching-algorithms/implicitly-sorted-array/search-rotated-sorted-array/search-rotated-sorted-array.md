Search target in rotated sorted array.

<br>

> **Key insight:** Binary search: determine which half is sorted, check if target is in sorted half.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Find sorted half, check if target in range, narrow search

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Find sorted half, check if target in range, narrow search`

### Time Complexity: O(log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
