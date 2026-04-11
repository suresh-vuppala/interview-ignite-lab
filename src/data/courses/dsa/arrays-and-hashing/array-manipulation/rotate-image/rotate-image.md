Rotate n×n matrix 90° clockwise in-place.

<br>

> Input: [[1,2,3],[4,5,6],[7,8,9]] → Output: [[7,4,1],[8,5,2],[9,6,3]]

<br>

---

## Constraints

- `1 ≤ n ≤ 20`

<br>

---

## All Possible Edge Cases

1. **1×1:** No change
2. **2×2:** Simple swap

<br>

---

## Solution 1: Extra Matrix

**Intuition:** Create new matrix. Place (i,j) at (j, n-1-i).

### Time Complexity: O(n²)
### Space Complexity: O(n²)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Uses O(n²) extra space for a copy. The problem asks for in-place rotation.
>
> **Insight:** 90° clockwise = Transpose + Reverse each row. Transpose swaps (i,j)→(j,i). Reversing rows maps (j,i)→(j,n-1-i). Combined: (i,j)→(j,n-1-i) which is exactly 90° clockwise.

<br>

---

## Solution 2: Transpose + Reverse Rows (Optimal)

**Intuition:** Step 1: Transpose. Step 2: Reverse each row.

### Time Complexity: O(n²)
### Space Complexity: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extra Matrix | O(n²) | O(n²) | Direct placement |
| Transpose+Reverse | O(n²) | O(1) | Two simple in-place operations |

<br>
<br>
