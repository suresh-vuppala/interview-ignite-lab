Place N queens on N×N board so no two attack each other.

<br>

> **Key insight:** Backtracking: place queen row by row, check column/diagonal conflicts.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Row-by-row placement, check col/diag1/diag2 sets

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Row-by-row placement, check col/diag1/diag2 sets`

### Time Complexity: O(N!)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N!) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
