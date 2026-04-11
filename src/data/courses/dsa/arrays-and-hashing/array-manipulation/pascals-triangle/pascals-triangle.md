Generate the first numRows of Pascal's triangle.

<br>

> Input: numRows = 5
> Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

<br>

---

## Constraints

- `1 ≤ numRows ≤ 30`

<br>

---

## All Possible Edge Cases

1. **numRows = 1:** [[1]]
2. **numRows = 2:** [[1],[1,1]]

<br>

---

## Solution 1: Row-by-Row Construction

**Intuition:**
Each row starts and ends with 1. Interior elements = sum of two elements above.

**Algorithm:**
1. For each row i (0 to numRows-1):
   - Create row of size i+1, fill with 1
   - For j from 1 to i-1: row[j] = prev_row[j-1] + prev_row[j]
   - Add to result

### Time Complexity: O(numRows²)
### Space Complexity: O(1) extra (output doesn't count)

This is already optimal since we must generate all numRows² elements.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Row-by-Row | O(n²) | O(1) extra | Direct construction from previous row |

**Note:** This problem has a single natural solution. The time complexity O(n²) is optimal since the output itself has O(n²) elements.

<br>
<br>

---

```code```
