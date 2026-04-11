Rotate an n×n matrix by 90° clockwise in-place.

<br>

> Input: [[1,2,3],[4,5,6],[7,8,9]]
> Output: [[7,4,1],[8,5,2],[9,6,3]]

<br>

---

## Constraints

- `n == matrix.length == matrix[i].length`
- `1 ≤ n ≤ 20`

<br>

---

## All Possible Edge Cases

1. **1×1:** No change
2. **2×2:** Simple 4-element swap
3. **Odd n:** Center stays

<br>

---

## Solution 1: Extra Matrix

**Intuition:**
Create new matrix. For each cell (i,j), place it at (j, n-1-i).

### Time Complexity: O(n²)
### Space Complexity: O(n²)

<br>

---

## Solution 2: Rotate Layer by Layer

**Intuition:**
Process each concentric ring. Swap 4 cells at a time in a cycle.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 3: Transpose + Reverse Rows (Optimal)

**Intuition:**
Step 1: Transpose (swap rows and columns). Step 2: Reverse each row. This achieves 90° clockwise rotation.

**Algorithm:**
1. Transpose: swap matrix[i][j] with matrix[j][i] for i < j
2. Reverse each row

### Time Complexity: O(n²)
### Space Complexity: O(1)

**Why it works:**
- Transpose: (i,j) → (j,i)
- Reverse row: (j,i) → (j, n-1-i)
- Combined: (i,j) → (j, n-1-i) = 90° clockwise rotation

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extra Matrix | O(n²) | O(n²) | Direct placement |
| Layer Rotation | O(n²) | O(1) | 4-way cycle swap |
| Transpose + Reverse | O(n²) | O(1) | Two simple operations compose to rotation |

<br>
<br>

---

```code```
