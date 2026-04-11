Given an m×n matrix, return all elements in spiral order. Traverse: right → down → left → up, shrinking boundaries after each direction.

<br>

---

## Constraints

- `1 ≤ m, n ≤ 10`
- `-100 ≤ matrix[i][j] ≤ 100`

<br>

---

## All Possible Edge Cases

1. **1×1 matrix:** Return single element
2. **Single row:** Return the row left to right
3. **Single column:** Return the column top to bottom
4. **Square matrix:** Standard spiral
5. **Wide rectangle:** More horizontal traversals
6. **Tall rectangle:** More vertical traversals
7. **2×2 matrix:** One complete spiral cycle

<br>

---

```code```
