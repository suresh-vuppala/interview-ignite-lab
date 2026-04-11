Given a binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area. Build histogram per row, apply Largest Rectangle in Histogram.

<br>

---

## Constraints

- `1 ≤ rows, cols ≤ 200`
- `matrix[i][j] is '0' or '1'`

<br>

---

## All Possible Edge Cases

1. **All zeros:** Return 0
2. **All ones:** Return rows × cols
3. **Single row:** Longest consecutive 1s
4. **Single column:** Longest consecutive 1s vertically
5. **1×1 matrix:** Return 0 or 1
6. **L-shaped ones:** Must find the largest rectangle within
7. **Diagonal ones:** Rectangles can't be diagonal

<br>

---

```code```
