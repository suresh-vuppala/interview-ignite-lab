Given an m×n matrix, if an element is 0, set its entire row and column to 0. Must be done in-place.

<br>

> Input:
> [[1,1,1],[1,0,1],[1,1,1]]

> Output:
> [[1,0,1],[0,0,0],[1,0,1]]

> Explanation:
> Element at (1,1) is 0. Set row 1 and column 1 to all zeros.
> 
> **Key insight:** Use the first row and first column of the matrix itself as marker arrays — O(1) extra space.

<br>



---

## Constraints

- `1 ≤ m, n ≤ 200`
- `-2³¹ ≤ matrix[i][j] ≤ 2³¹ - 1`

<br>

---

## All Possible Edge Cases

1. **No zeros:** Matrix unchanged
2. **All zeros:** Stays all zeros
3. **Zero in first row/col:** Needs special handling
4. **1×1 matrix:** Trivial

<br>

---

## Solution 1: Extra Sets for Rows & Columns

**Intuition:**
Record which rows and columns contain zeros. Second pass to zero them out.

**Algorithm:**
1. Scan matrix: if matrix[i][j] == 0, add i to rowSet, j to colSet
2. Second pass: if i in rowSet or j in colSet → matrix[i][j] = 0

### Time Complexity: O(M × N)
**Why?**
- Two passes over M×N matrix
- Set operations: O(1) each

**Detailed breakdown:**
- Matrix 200×200 → 80,000 operations (two passes)

### Space Complexity: O(M + N)
**Why?**
- rowSet up to M entries, colSet up to N entries

> **Drawback:**
> Uses O(M+N) extra space for the row and column sets. Can we reduce to O(1) auxiliary space?

> **Key Insight for Improvement:**
> Use the FIRST ROW and FIRST COLUMN of the matrix itself as marker arrays. matrix[0][j]=0 means "column j should be zeroed", matrix[i][0]=0 means "row i should be zeroed". Two boolean flags track whether the first row/column themselves need zeroing.

<br>

---

## Solution 2: First Row/Column as Markers (Optimal)

**Intuition:**
First row stores column markers, first column stores row markers. Process in 4 steps.

**Algorithm:**
1. Check if first row has any zeros → firstRowZero flag
2. Check if first column has any zeros → firstColZero flag
3. Use first row/col as markers: scan rest of matrix, if 0 → mark matrix[i][0]=0, matrix[0][j]=0
4. Zero out based on markers (rows 1+, cols 1+)
5. Handle first row (if firstRowZero)
6. Handle first col (if firstColZero)

### Time Complexity: O(M × N)
**Why?**
- Multiple passes but each is O(M×N) or O(M) or O(N)

**Detailed breakdown:**
- Matrix 200×200 → ~160,000 operations (two passes + edges)

**Example walkthrough:**
```
Input: [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Step 1: firstRowZero = true (row 0 has zeros)
Step 2: firstColZero = true (col 0 has zero at (0,0))
Step 3: Mark — matrix[0][3]=0 already → col 3 marked
        matrix[0][0]=0 already → row 0 marked
Step 4: Zero using markers:
        [[0,1,2,0],[0,4,5,0],[1,3,1,5]]
Step 5: First row → all zeros: [[0,0,0,0],...]
Step 6: First col → all zeros: [[0,...],[0,...],[0,...]]

Final: [[0,0,0,0],[0,4,5,0],[0,3,1,5]]
```

### Space Complexity: O(1)
**Why?**
- Only two boolean flags (firstRowZero, firstColZero)
- Reusing matrix space for markers

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Row/Col Sets | O(M×N) | O(M+N) | Record affected rows/cols |
| First Row/Col Markers | O(M×N) | O(1) | Matrix itself as markers |

**Recommended Solution:** First Row/Col Markers (Solution 2) — O(M×N) time, O(1) space.

**Key Insights:**
1. **Sets → Matrix markers:** First row = col markers, first col = row markers
2. **Order matters:** Process inner cells first, handle first row/col last
3. **Two flags:** Track first row/col separately since they're used as markers


<br>
<br>

---

```code```
