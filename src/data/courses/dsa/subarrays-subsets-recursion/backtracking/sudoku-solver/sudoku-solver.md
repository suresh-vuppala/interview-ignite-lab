Fill a 9×9 Sudoku grid following row, column, and 3×3 box uniqueness rules.

<br>

> Partially filled grid → complete valid grid
>
> **Key insight:** Backtracking: find empty cell, try digits 1-9. Check row/col/box constraints. If valid, recurse. If stuck, backtrack.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Try all assignments

### Time Complexity: O(9^81)

> **Drawback:**
> Most assignments are invalid.

> **Key Insight for Improvement:**
> Constraint propagation + backtracking. Use sets for row/col/box to check in O(1). Choose cell with fewest candidates for faster pruning.

<br>

---

## Solution 2: Backtracking + Constraint Sets (Optimal)

**Intuition:** Backtracking: find empty cell, try digits 1-9. Check row/col/box constraints. If valid, recurse. If stuck, backtrack.

**Algorithm:**
1. Find next empty cell
2. For digit 1-9:
   - If valid (not in row set, col set, box set): place digit
   - Recurse to next empty cell
   - If stuck: remove digit, try next
3. If all digits tried: return false (backtrack)

### Time Complexity: O(9^empty)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Find empty (0,2). Try 1: conflicts. Try 2: valid→place→recurse...
If dead end→backtrack, try 3...until solution found
```

### Space Complexity: O(81)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all assignments | O(9^81) | Varies | Baseline |
| Backtracking + Constraint Sets | O(9^empty) | O(81) | Optimal |

**Recommended Solution:** Backtracking + Constraint Sets

**Key Insights:**
1. **Three constraint sets:** row[9][9], col[9][9], box[9][9]
2. **Box index:** (row/3)*3 + col/3
3. **MRV heuristic:** Choose cell with minimum remaining values first

<br><br>

---

```code```
