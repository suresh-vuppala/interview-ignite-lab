Given an m×n matrix, if an element is 0, set its entire row and column to 0. Must solve in-place. Optimal: use first row and first column as markers for O(1) extra space.

<br>

---

## Constraints

- `1 ≤ m, n ≤ 200`
- `-2³¹ ≤ matrix[i][j] ≤ 2³¹ - 1`
- `Must modify in-place`

<br>

---

## All Possible Edge Cases

1. **No zeros:** Matrix unchanged
2. **All zeros:** Entire matrix stays zero
3. **Single zero:** Its entire row and column become zero
4. **Zero in corner:** Affects first row and first column
5. **1×1 matrix:** If 0, stays 0; otherwise unchanged
6. **Zeros in same row:** Column effects accumulate
7. **Zeros in same column:** Row effects accumulate
8. **Use first row/col as markers:** O(1) space solution

<br>

---

```code```
