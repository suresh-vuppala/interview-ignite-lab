Given an integer numRows, return the first numRows of Pascal's triangle. Each number is the sum of the two numbers directly above it.

<br>

> Input:
> numRows = 5

> Output:
> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

> Explanation:
> Row 0: [1]. Row 1: [1,1]. Row 2: [1, 1+1=2, 1]. Row 3: [1, 1+2=3, 2+1=3, 1]. And so on.
> 
> **Key insight:** Each row starts and ends with 1. Interior elements: row[j] = prevRow[j-1] + prevRow[j].

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

## Solution 1: Row-by-Row Construction (Optimal)

**Intuition:**
Build each row from the previous one. First/last elements are 1. Middle elements are the sum of two elements from the previous row.

**Algorithm:**
1. Initialize result = []
2. For each row i (0 to numRows-1):
   - Create row of size (i+1), fill with 1s
   - For j = 1 to i-1: row[j] = result[i-1][j-1] + result[i-1][j]
   - Append row to result
3. Return result

### Time Complexity: O(N²)
**Why?**
- Row i has (i+1) elements
- Total elements: 1 + 2 + 3 + ... + N = N(N+1)/2 = O(N²)
- Must generate all elements — cannot do better

**Detailed breakdown:**
- numRows = 30 → 30×31/2 = 465 elements
- Each element computed in O(1)
- Total: 465 operations

### Space Complexity: O(1) extra
**Why?**
- Only the result structure (which is required output)
- No auxiliary data structures

**Example walkthrough:**
```
numRows = 5

Row 0: [1]
Row 1: [1, 1]
Row 2: [1, 1+1=2, 1]
Row 3: [1, 1+2=3, 2+1=3, 1]
Row 4: [1, 1+3=4, 3+3=6, 3+1=4, 1]

Result: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]] ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Row-by-Row | O(N²) | O(1) extra | Direct construction — already optimal |

**Recommended Solution:** Row-by-Row Construction — O(N²) time.

**Key Insights:**
1. **Already optimal:** Output has O(N²) elements — must be at least O(N²)
2. **Space optimization:** Can generate row from only the previous row (O(N) rolling)
3. **Math connection:** Element (i,j) = C(i,j) = i! / (j! × (i-j)!)


<br>
<br>

---

```code```
