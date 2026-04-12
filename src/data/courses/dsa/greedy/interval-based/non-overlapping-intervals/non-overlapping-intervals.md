Remove minimum intervals to make rest non-overlapping.

<br>

> **Key insight:** Sort by end time. Count overlaps = total - max non-overlapping.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** N - activity_selection_count

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `N - activity_selection_count`

### Time Complexity: O(N log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
