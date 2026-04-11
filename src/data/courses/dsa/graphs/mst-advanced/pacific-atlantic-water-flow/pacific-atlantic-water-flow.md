Given an m×n matrix of heights, find all cells where water can flow to both the Pacific (top/left edges) and Atlantic (bottom/right edges) oceans.

<br>

---

## Constraints

- `1 ≤ m, n ≤ 200`
- `0 ≤ heights[i][j] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **1×1 grid:** That cell reaches both oceans
2. **All same height:** Every cell reaches both oceans
3. **Strictly increasing left to right:** Only rightmost column + bottom row
4. **Single row:** Left border → Pacific, right border → Atlantic
5. **Single column:** Top → Pacific, bottom → Atlantic

<br>

---

```code```
