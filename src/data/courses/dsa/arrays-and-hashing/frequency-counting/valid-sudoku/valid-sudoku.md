Determine if a 9×9 Sudoku board is valid. Each row, column, and 3×3 box must contain 1-9 without repetition.

<br>

> **Key insight:** Track seen digits per row, column, and box using encoded set entries.

<br>

---

## Constraints

- `board.length == 9`, cells are '1'-'9' or '.'

<br>

---

## All Possible Edge Cases

1. **All empty:** Valid
2. **Duplicate in row/col/box:** Invalid

<br>

---

## Solution 1: Three Separate Checks

**Intuition:** Check each row, column, and 3×3 box separately using sets.

### Time Complexity: O(81) = O(1)
### Space Complexity: O(81) = O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Three separate passes over the board — one for rows, one for cols, one for boxes. Each cell is visited 3 times.
>
> **Insight:** Process each cell ONCE. For each (i,j) with digit d, encode three membership checks into a single set: "d in row i", "d in col j", "d in box (i/3,j/3)". One pass, one set.

<br>

---

## Solution 2: Single Pass with Encoded Set (Optimal)

**Intuition:** One pass. Encode row/col/box membership as strings in a single HashSet.

### Time Complexity: O(81) = O(1)
### Space Complexity: O(81) = O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Three Passes | O(1) | O(1) | Separate row/col/box checks |
| Single Pass | O(1) | O(1) | One pass with encoded keys |

<br>
<br>
