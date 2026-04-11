Find the largest rectangle containing only 1's in a binary matrix.

<br>

> Input: [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]]
> Output: 6

> **Key insight:** Build histogram per row, apply Largest Rectangle in Histogram to each.

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
3. **Single row/column:** Longest consecutive 1s
4. **1×1 matrix:** Return 0 or 1

<br>

---

## Solution 1: Brute Force

**Intuition:** For each cell as top-left, try all possible bottom-right corners, check if all 1s.

### Time Complexity: O(m² × n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Histogram per Row + Stack (Optimal)

**Intuition:**
Treat each row as a histogram base. heights[j] = number of consecutive 1s above (including current row). Apply "Largest Rectangle in Histogram" to each row's histogram.

**Algorithm:**
1. For each row:
   - Update heights: if cell is '1', heights[j]++; else heights[j] = 0
   - Apply largest rectangle in histogram algorithm
   - Track maxArea

### Time Complexity: O(m × n)
### Space Complexity: O(n) — heights array + stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(m²×n²) | O(1) | Check all rectangles |
| Histogram + Stack | O(m×n) | O(n) | Reduce to 1D histogram per row |

<br>
<br>

---

```code```
