2D prefix sum for rectangular region queries.

<br>

> matrix, sumRegion(r1,c1,r2,c2) → sum of rectangle
>
> **Key insight:** 2D prefix sum + inclusion-exclusion. prefix[i][j] = sum of rectangle (0,0)→(i-1,j-1). Query uses 4 prefix lookups.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: Sum rectangle each query

**Intuition:**
The most straightforward approach. Recomputing sum for every query.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(M×N) per query
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Recomputing sum for every query.

> **Key Insight for Improvement:**
> 2D prefix sum: build in O(M×N), query in O(1) using inclusion-exclusion formula.

<br>

---

## Solution 2: 2D Prefix Sum (Optimal)

**Intuition:** 2D prefix sum + inclusion-exclusion. prefix[i][j] = sum of rectangle (0,0)→(i-1,j-1). Query uses 4 prefix lookups.

**Algorithm:**
1. Build: prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+matrix[i-1][j-1]
2. Query: sum = prefix[r2+1][c2+1]-prefix[r1][c2+1]-prefix[r2+1][c1]+prefix[r1][c1]

### Time Complexity: O(1) per query, O(MN) build
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
2×2 matrix [[1,2],[3,4]]: prefix=[[0,0,0],[0,1,3],[0,4,10]]
sumRegion(0,0,1,1)=10-0-0+0=10 ✓
```

### Space Complexity: O(MN)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sum rectangle each query | O(M×N) per query | Varies | Baseline |
| 2D Prefix Sum | O(1) per query, O(MN) build | O(MN) | Optimal approach |

**Recommended Solution:** 2D Prefix Sum — O(1) per query, O(MN) build time.

**Key Insights:**
1. **Inclusion-exclusion:** Add two sides, subtract double-counted corner
2. **1-indexed prefix:** Avoids boundary checks
3. **Extension of 1D:** Same concept in two dimensions

<br><br>

---

```code```
