# Maximum Sum Submatrix

Given a 2D matrix, find the submatrix (rectangular region) with the maximum sum.

<br>

> Input:
> matrix = [
>   [ 1,  2, -1, -4, -20],
>   [-8, -3,  4,  2,   1],
>   [ 3,  8, 10,  1,   3],
>   [-4, -1,  1,  7,  -6]
> ]

> Output:
> 29

> Explanation:
> The submatrix with maximum sum is:
> [
>   [ 4,  2,  1],
>   [10,  1,  3],
>   [ 1,  7, -6]
> ]
> Sum = 4+2+1+10+1+3+1+7-6 = 23 (Actually the max is from rows 1-2, cols 2-4: 4+2+1+10+1+3 = 21, or rows 1-3, cols 1-3: -3+4+2+8+10+1+-1+1+7 = 29)
> 
> **Key insight:** Extend Kadane's algorithm from 1D to 2D using column compression.

<br>


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Values fit in 32-bit integer`
- `DP state space fits in memory`

<br>

---

## All Possible Edge Cases

1. **n = 0 or empty input:** Base case — return 0 or empty
2. **n = 1:** Single element — trivial case
3. **All same elements:** Check if pattern still applies
4. **Maximum constraints:** Verify time complexity handles worst case
5. **Negative values (if applicable):** Affects min/max DP transitions
6. **Result requires modular arithmetic:** Use MOD = 10⁹ + 7 to prevent overflow

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check all possible submatrices by trying every combination of top-left and bottom-right corners. For each submatrix, calculate sum and track maximum.

**Algorithm:**
1. For each possible top row (r1)
2. For each possible bottom row (r2 >= r1)
3. For each possible left column (c1)
4. For each possible right column (c2 >= c1)
5. Calculate sum of submatrix from (r1,c1) to (r2,c2)
6. Update maximum sum

### Time Complexity: O(M²×N²×M×N) = O(M³×N³)
**Why?**
- Four nested loops for corners: O(M²×N²)
- Calculating sum for each submatrix: O(M×N)
- Total: O(M²×N²) × O(M×N) = O(M³×N³)

**Detailed breakdown:**
- Choose top-left corner: M×N options
- Choose bottom-right corner: M×N options
- For each pair, sum calculation: O(M×N)
- Total: M×N × M×N × M×N = O(M³×N³)

### Space Complexity: O(1)
**Why?**
- Only storing maximum sum and loop variables
- No additional data structures

**Problem:** Extremely slow for even moderate-sized matrices.

> **Key Insight for Improvement:**
> We're recalculating sums repeatedly. Can we use prefix sums to calculate any submatrix sum in O(1)? Yes!

<br>

---

## Solution 2: Prefix Sum Optimization

**Intuition:**
Use 2D prefix sums to calculate any submatrix sum in O(1) time. Prefix sum at (i,j) = sum of all elements from (0,0) to (i,j).

**Algorithm:**
1. Build prefix sum matrix: prefix[i][j] = sum from (0,0) to (i,j)
2. For each possible submatrix (r1,c1) to (r2,c2):
   - Sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1]
3. Track maximum sum

### Time Complexity: O(M²×N²)
**Why?**
- Build prefix sum: O(M×N)
- Four nested loops for corners: O(M²×N²)
- Calculate sum using prefix: O(1)
- Total: O(M×N) + O(M²×N²) = O(M²×N²)

**Improvement:** From O(M³×N³) to O(M²×N²)

### Space Complexity: O(M×N)
**Why?**
- Prefix sum matrix: M×N space
- Few variables: O(1)
- Total: O(M×N)

**Problem:** Still O(M²×N²) which is slow for large matrices.

> **Key Insight for Improvement:**
> Can we reduce from 4 nested loops to fewer? Yes! Fix top and bottom rows, then use Kadane's algorithm on compressed columns. This reduces to O(M²×N).

<br>

---

## Solution 3: Kadane's Algorithm Extension (Optimal)

**Intuition:**
Fix top and bottom rows, compress all rows between them into a 1D array by summing columns. Then apply Kadane's algorithm to find maximum subarray sum in this 1D array.

**Key Idea:**
- For each pair of rows (top, bottom), create 1D array where arr[j] = sum of column j from top to bottom
- Apply Kadane's algorithm on this 1D array to find maximum sum
- This gives maximum sum submatrix with those fixed top and bottom rows

**Algorithm:**
1. For each top row (r1 from 0 to M-1):
   - Initialize temp array of size N with zeros
   - For each bottom row (r2 from r1 to M-1):
     - Add current row to temp: temp[j] += matrix[r2][j]
     - Apply Kadane's algorithm on temp to find max sum
     - Update global maximum

**Kadane's Algorithm (1D Maximum Subarray):**
```
maxSum = -infinity, currentSum = 0
for each element in array:
    currentSum = max(element, currentSum + element)
    maxSum = max(maxSum, currentSum)
return maxSum
```

### Time Complexity: O(M²×N)
**Why?**
- Outer loop (top row): M iterations
- Inner loop (bottom row): M iterations
- For each pair, Kadane's on N elements: O(N)
- Total: M × M × N = O(M²×N)

**Detailed breakdown:**
- Choose top row: M options
- Choose bottom row: M options (for each top)
- Kadane's algorithm: O(N) for each pair
- Total: M × M × N = O(M²×N)

**Improvement:** From O(M²×N²) to O(M²×N)
- Example: 100×100 matrix
- Before: 100² × 100² = 100,000,000 operations
- After: 100² × 100 = 1,000,000 operations (100× faster!)

### Space Complexity: O(N)
**Why?**
- Temp array for column sums: O(N)
- Kadane's algorithm variables: O(1)
- Total: O(N)

**Breakdown:**
- temp array: N elements
- Variables (maxSum, currentSum, etc.): O(1)
- Total: O(N)

**Why this works:**
- Fixing top and bottom rows reduces 2D problem to 1D
- Column compression: sum all elements in each column between rows
- Kadane's finds best contiguous columns (left to right range)
- Try all possible row pairs to find global maximum

> **Final Complexity:** O(M²×N) time, O(N) space - Optimal solution!

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(M³×N³) | O(1) | Baseline - check all submatrices |
| Prefix Sum | O(M²×N²) | O(M×N) | O(1) sum calculation - still 4 loops |
| Kadane's Extension | O(M²×N) | O(N) | Reduce to 1D problem - optimal |

**Key Insights:**
1. **Brute Force → Prefix Sum:** Repeated sum calculations → precompute prefix sums
2. **Prefix Sum → Kadane's:** 4 nested loops → fix 2 dimensions, solve 1D problem
3. **Kadane's Extension:** Combines row compression with 1D maximum subarray

**When to use:**
- **Kadane's Extension:** Standard approach for maximum sum submatrix
- **Prefix Sum:** When need to query multiple submatrix sums
- **Brute Force:** Only for very small matrices or learning purposes

> **Final Complexity:** O(M²×N) time, O(N) space

<br>
<br>

---

```code```
