Fill 9×9 Sudoku grid following rules.

<br>

> **Key insight:** Backtracking: try 1-9 in each empty cell, validate row/col/box.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Try digits 1-9, validate, backtrack on conflict

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Try digits 1-9, validate, backtrack on conflict`

### Time Complexity: O(9^empty)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(9^empty) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
