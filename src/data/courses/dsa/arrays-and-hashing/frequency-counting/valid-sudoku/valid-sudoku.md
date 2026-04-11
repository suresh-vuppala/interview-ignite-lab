Determine if a 9×9 Sudoku board is valid. A valid board has no duplicate digits 1-9 in any row, column, or 3×3 sub-box. Empty cells are marked with '.'.

<br>

> Input:
> A partially filled 9×9 board

> Output:
> true or false

> Explanation:
> Check each row, column, and 3×3 box for duplicate digits. Only filled cells matter.
> 
> **Key insight:** Encode each digit's membership in a single set using composite keys like "(d) in row (r)" — one pass, one set.

<br>



---

## Constraints

- `board.length == 9`, `board[i].length == 9`
- `board[i][j]` is a digit '1'-'9' or '.'

<br>

---

## All Possible Edge Cases

1. **All empty:** Valid (no conflicts possible)
2. **Full valid board:** All rules satisfied
3. **Duplicate in row:** Same digit twice in a row
4. **Duplicate in column:** Same digit twice in a column
5. **Duplicate in 3×3 box:** Same digit twice in a sub-box but different row/col

<br>

---

## Solution 1: Three Separate Passes

**Intuition:**
Check rows, columns, and 3×3 boxes separately. Use a fresh set for each unit.

**Algorithm:**
1. Check each of 9 rows for duplicates
2. Check each of 9 columns for duplicates
3. Check each of 9 sub-boxes for duplicates
4. If any duplicate found → false, else true

### Time Complexity: O(81) = O(1)
**Why?**
- Board is always 9×9 — fixed size
- Three passes over 81 cells = 243 checks
- Constant regardless of input

**Detailed breakdown:**
- 9 rows × 9 cells = 81 checks
- 9 cols × 9 cells = 81 checks
- 9 boxes × 9 cells = 81 checks
- Total: 243 set operations

### Space Complexity: O(1)
**Why?**
- Each set holds at most 9 elements
- Fixed number of sets

> **Drawback:**
> Three separate passes over the board — each cell visited 3 times. While correct, we're doing redundant iterations. Code is also verbose with three nested loop structures.

> **Key Insight for Improvement:**
> Process each cell ONCE. For each digit d at position (r,c), check three membership conditions simultaneously using a single set with composite keys: "(d) in row (r)", "(d) in col (c)", "(d) in box (r/3,c/3)".

<br>

---

## Solution 2: Single Pass with Encoded Set (Optimal)

**Intuition:**
In one pass, for each filled cell, create three encoded strings representing its row, column, and box memberships. If any already exists in the set → invalid.

**Algorithm:**
1. Create one hash set
2. For each cell (i,j) with digit d:
   - Check/add: "d in row i"
   - Check/add: "d in col j"
   - Check/add: "d in box (i/3)(j/3)"
   - If any already in set → return false
3. No conflicts → return true

### Time Complexity: O(81) = O(1)
**Why?**
- Single pass over 81 cells
- 3 set operations per filled cell
- At most 243 operations total

**Detailed breakdown:**
- One pass: 81 cells
- Per cell: 3 string constructions + 3 set checks
- Total: up to 243 operations (same as Solution 1 but one loop)

**Example walkthrough:**
```
Cell (0,0) = '5':
  Add "5 row 0" → set
  Add "5 col 0" → set
  Add "5 box 00" → set

Cell (0,1) = '3':
  Add "3 row 0" → set
  Add "3 col 1" → set
  Add "3 box 00" → set

Cell (2,1) = '5':
  Check "5 col 1" → not in set ✓
  Check "5 box 00" → already in set! → return false
```

### Space Complexity: O(1)
**Why?**
- Set holds at most 81 × 3 = 243 entries — fixed bound

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Three Passes | O(1) | O(1) | Separate row/col/box checks |
| Single Pass | O(1) | O(1) | One loop with encoded set keys |

**Recommended Solution:** Single Pass (Solution 2) — cleaner code, one loop.

**Key Insights:**
1. **Encoding trick:** Composite keys encode three constraints in one set
2. **Fixed-size board:** Both solutions are technically O(1) since board is always 9×9
3. **Single pass:** One iteration is cleaner and faster in practice


<br>
<br>

---

```code```
