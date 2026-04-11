Given an n×n matrix, rotate it 90 degrees clockwise in-place.

<br>

> Input:
> [[1,2,3],[4,5,6],[7,8,9]]

> Output:
> [[7,4,1],[8,5,2],[9,6,3]]

> Explanation:
> Row 1 [1,2,3] becomes Column 3 [1,2,3] reading top-to-bottom.
> 
> **Key insight:** 90° clockwise rotation = Transpose the matrix + Reverse each row. Two simple in-place operations.

<br>



---

## Constraints

- `1 ≤ n ≤ 20`
- `-1000 ≤ matrix[i][j] ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **1×1 matrix:** No change
2. **2×2 matrix:** Simple corner swap

<br>

---

## Solution 1: Use Extra Matrix

**Intuition:**
Create a new matrix. Place element (i,j) at position (j, n-1-i) in the new matrix.

**Algorithm:**
1. Create copy of matrix
2. For each (i,j): result[j][n-1-i] = copy[i][j]
3. Copy result back to original

### Time Complexity: O(N²)
**Why?**
- Visit all N² elements once

**Detailed breakdown:**
- Matrix 20×20 → 400 operations

### Space Complexity: O(N²)
**Why?**
- Full copy of the matrix

> **Drawback:**
> Uses O(N²) extra space for the copy. The problem requires in-place rotation — no extra matrix allowed.

> **Key Insight for Improvement:**
> 90° clockwise = Transpose + Reverse each row. Transpose swaps (i,j)→(j,i). Reversing rows then maps (j,i)→(j,n-1-i). Combined: (i,j)→(j,n-1-i) — exactly 90° clockwise rotation. Both operations are in-place.

<br>

---

## Solution 2: Transpose + Reverse Rows (Optimal)

**Intuition:**
Step 1: Transpose (swap matrix[i][j] with matrix[j][i]).
Step 2: Reverse each row.
The composition gives 90° clockwise rotation.

**Algorithm:**
1. Transpose: for i=0..n-1, for j=i+1..n-1: swap(matrix[i][j], matrix[j][i])
2. Reverse: for each row: reverse(row)

### Time Complexity: O(N²)
**Why?**
- Transpose: N²/2 swaps
- Reverse: N²/2 swaps
- Total: N² operations

**Detailed breakdown:**
- Matrix 20×20 → ~400 swaps total

**Example walkthrough:**
```
Original:   Transpose:   Reverse rows:
1 2 3       1 4 7        7 4 1
4 5 6  →    2 5 8   →    8 5 2
7 8 9       3 6 9        9 6 3  ✓
```

### Space Complexity: O(1)
**Why?**
- All swaps done in-place — no extra storage

**Why this is optimal:**
- Must touch every element: O(N²) minimum
- O(1) space — purely in-place

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extra Matrix | O(N²) | O(N²) | Direct placement in copy |
| Transpose+Reverse | O(N²) | O(1) | Two in-place operations |

**Recommended Solution:** Transpose + Reverse (Solution 2) — O(N²) time, O(1) space.

**Key Insights:**
1. **Rotation decomposition:** 90° CW = Transpose + Reverse rows
2. **Other rotations:** 90° CCW = Transpose + Reverse columns; 180° = Reverse rows + Reverse columns
3. **Both operations O(1) space:** Pure in-place swaps


<br>
<br>

---

```code```
