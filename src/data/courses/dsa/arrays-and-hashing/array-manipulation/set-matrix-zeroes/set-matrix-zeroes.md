Given an m×n matrix, if an element is 0, set its entire row and column to 0. Must solve in-place.

<br>

> Input: [[1,1,1],[1,0,1],[1,1,1]]
> Output: [[1,0,1],[0,0,0],[1,0,1]]

<br>

---

## Constraints

- `1 ≤ m, n ≤ 200`
- `-2³¹ ≤ matrix[i][j] ≤ 2³¹ - 1`

<br>

---

## All Possible Edge Cases

1. **No zeros:** Unchanged
2. **All zeros:** Stays all zeros
3. **Single zero:** Its row and column zeroed
4. **1×1 matrix:** Trivial

<br>

---

## Solution 1: Extra Matrix

**Intuition:**
Copy the matrix. Use copy to determine which cells should be zero.

### Time Complexity: O(m × n)
### Space Complexity: O(m × n)

<br>

---

## Solution 2: Row + Column Sets

**Intuition:**
First pass: record which rows and columns contain zeros. Second pass: zero out those rows/columns.

### Time Complexity: O(m × n)
### Space Complexity: O(m + n)

> **Key Insight:** Use the first row and first column of the matrix itself as markers.

<br>

---

## Solution 3: In-Place with First Row/Col as Markers

**Intuition:**
Use matrix[i][0] and matrix[0][j] as flags. Two boolean variables track if first row/col themselves need zeroing.

**Algorithm:**
1. Check if first row/col have zeros → set flags
2. For cells (i>0, j>0): if zero, mark matrix[i][0] = matrix[0][j] = 0
3. For cells (i>0, j>0): if marker is 0, zero the cell
4. Handle first row/col using flags

### Time Complexity: O(m × n)
### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extra Matrix | O(m×n) | O(m×n) | Copy to preserve originals |
| Row/Col Sets | O(m×n) | O(m+n) | Track affected rows/cols |
| First Row/Col Markers | O(m×n) | O(1) | Use matrix itself as marker |

<br>
<br>

---

```code```
