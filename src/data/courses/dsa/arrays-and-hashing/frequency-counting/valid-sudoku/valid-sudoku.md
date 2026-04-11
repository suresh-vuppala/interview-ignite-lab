Determine if a 9×9 Sudoku board is valid. Only filled cells need to be validated: each row, column, and 3×3 sub-box must contain digits 1-9 without repetition.

<br>

---

## Constraints

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j] is a digit '1'-'9' or '.'`

<br>

---

## All Possible Edge Cases

1. **Valid complete board:** All constraints satisfied
2. **Empty cells only:** All '.' — valid by default
3. **Duplicate in row:** Two same digits in one row → false
4. **Duplicate in column:** Two same digits in one column → false
5. **Duplicate in 3×3 box:** Two same digits in one box → false
6. **Only checking filled cells:** Don't validate if board is solvable, only current state
7. **Single digit filled:** Always valid

<br>

---

```code```
