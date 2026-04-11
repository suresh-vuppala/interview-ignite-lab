Given numRows, generate the first numRows of Pascal's triangle. Each row starts and ends with 1, and each interior element is the sum of the two elements directly above it.

<br>

---

## Constraints

- `1 ≤ numRows ≤ 30`

<br>

---

## All Possible Edge Cases

1. **numRows = 1:** Return [[1]]
2. **numRows = 2:** Return [[1],[1,1]]
3. **Large numRows:** Values can get large but fit in int for n ≤ 30
4. **Each row starts and ends with 1:** Interior = sum of two above
5. **Row k has k+1 elements:** Size grows linearly

<br>

---

```code```
