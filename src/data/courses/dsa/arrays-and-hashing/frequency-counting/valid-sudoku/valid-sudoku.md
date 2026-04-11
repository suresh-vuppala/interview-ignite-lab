Determine if a 9×9 Sudoku board is valid. Only filled cells need to be validated: each row, column, and 3×3 sub-box must contain digits 1-9 without repetition.

<br>

> Input: Partially filled 9×9 board
> Output: true/false

> **Key insight:** Track seen digits per row, column, and 3×3 box using sets.

<br>

---

## Constraints

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j] is '1'-'9' or '.'`

<br>

---

## All Possible Edge Cases

1. **Empty cells only:** All '.' — valid
2. **Duplicate in row/col/box:** Invalid
3. **Single digit filled:** Always valid

<br>

---

## Solution 1: Brute Force (Three Separate Checks)

**Intuition:**
Check each row, each column, and each 3×3 box separately for duplicates.

**Algorithm:**
1. For each row: check 9 cells for duplicates
2. For each column: check 9 cells for duplicates
3. For each 3×3 box: check 9 cells for duplicates

### Time Complexity: O(81) = O(1)
### Space Complexity: O(9) per check

<br>

---

## Solution 2: Single Pass with Encoding

**Intuition:**
In one pass, for each filled cell, check if we've seen this digit in the same row, column, or box using a single set with encoded strings.

**Algorithm:**
1. Create a HashSet
2. For each cell (i, j) with digit d:
   - Check if "(d) in row i" is in set
   - Check if "(d) in col j" is in set
   - Check if "(d) in box i/3-j/3" is in set
   - If any exists → false
   - Add all three encodings to set

### Time Complexity: O(81) = O(1)
### Space Complexity: O(81) = O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Three Checks | O(1) | O(1) | Separate row/col/box passes |
| Single Pass | O(1) | O(1) | One pass with encoded keys |

**Recommended:** Single Pass — cleaner code, same complexity.

<br>
<br>

---

```code```
