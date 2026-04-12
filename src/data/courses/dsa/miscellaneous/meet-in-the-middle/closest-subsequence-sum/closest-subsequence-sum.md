Find subsequence sum closest to a goal.

<br>

> **Key insight:** Meet in the middle: generate all sums for each half, sort, two-pointer.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Meet in middle + sort + two-pointer for closest

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Meet in middle + sort + two-pointer for closest`

### Time Complexity: O(2^(N/2) log)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(2^(N/2))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(2^(N/2) log) | O(2^(N/2)) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
