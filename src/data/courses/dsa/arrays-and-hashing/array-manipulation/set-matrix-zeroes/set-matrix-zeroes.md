Given m×n matrix, if element is 0, set its entire row and column to 0. In-place.

<br>

> Input: [[1,1,1],[1,0,1],[1,1,1]] → Output: [[1,0,1],[0,0,0],[1,0,1]]

<br>

---

## Constraints

- `1 ≤ m, n ≤ 200`

<br>

---

## All Possible Edge Cases

1. **No zeros:** Unchanged
2. **All zeros:** Stays all zeros
3. **1×1:** Trivial

<br>

---

## Solution 1: Extra Sets for Rows & Columns

**Intuition:** Record which rows and columns contain zeros. Second pass to zero them.

### Time Complexity: O(m × n)
### Space Complexity: O(m + n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Uses O(m+n) space for the row/column sets. Can we reduce to O(1)?
>
> **Insight:** Use the FIRST ROW and FIRST COLUMN of the matrix itself as marker arrays. Two boolean flags track whether the first row/column themselves need zeroing.

<br>

---

## Solution 2: First Row/Col as Markers (Optimal)

**Intuition:** Use matrix[i][0] and matrix[0][j] as zero flags.

### Time Complexity: O(m × n)
### Space Complexity: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Row/Col Sets | O(m×n) | O(m+n) | Record affected rows/cols |
| First Row/Col Markers | O(m×n) | O(1) | Matrix itself as markers |

<br>
<br>
