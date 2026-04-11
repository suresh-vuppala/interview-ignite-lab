Rotate an n×n 2D matrix by 90 degrees clockwise in-place. Approach: transpose the matrix (swap rows and columns), then reverse each row.

<br>

---

## Constraints

- `n == matrix.length == matrix[i].length`
- `1 ≤ n ≤ 20`
- `-1000 ≤ matrix[i][j] ≤ 1000`
- `Must rotate in-place`

<br>

---

## All Possible Edge Cases

1. **1×1 matrix:** No rotation needed
2. **2×2 matrix:** Simple 4-element swap
3. **3×3 matrix:** Standard case — one layer to rotate
4. **Even dimension:** Two nested layers
5. **Odd dimension:** Center element stays in place
6. **All same values:** Matrix looks unchanged after rotation

<br>

---

```code```
