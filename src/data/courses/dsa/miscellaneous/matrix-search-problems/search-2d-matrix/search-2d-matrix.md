Search for target in a matrix where each row is sorted and first element of each row > last of previous.

<br>

> matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]], target=3 → true
>
> **Key insight:** Treat as 1D sorted array. Binary search with index mapping: row=mid/cols, col=mid%cols.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Scan entire matrix

**Intuition:**
The most straightforward approach. Linear scan ignores sorted structure.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

### Time Complexity: O(M×N)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Linear scan ignores sorted structure.

> **Key Insight for Improvement:**
> Single binary search: treat M×N matrix as sorted 1D array. Map index: row=mid/N, col=mid%N.

<br>

---

## Solution 2: Flattened Binary Search (Optimal)

**Intuition:** Treat as 1D sorted array. Binary search with index mapping: row=mid/cols, col=mid%cols.

**Algorithm:**
1. lo=0, hi=M×N-1
2. While lo ≤ hi:
   - mid = lo+(hi-lo)/2
   - val = matrix[mid/N][mid%N]
   - Compare with target → narrow search

### Time Complexity: O(log(M×N))
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
3×4 matrix, target=11: lo=0,hi=11, mid=5→matrix[1][1]=11 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Scan entire matrix | O(M×N) | Varies | Baseline |
| Flattened Binary Search | O(log(M×N)) | O(1) | Optimal |

**Recommended Solution:** Flattened Binary Search

**Key Insights:**
1. **row=mid/cols, col=mid%cols:** Index mapping for flattened view
2. **O(log(MN)):** Single binary search over all elements
3. **Alternative:** Binary search row, then binary search column

<br><br>

---

```code```
