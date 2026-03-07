# Maximum Path Sum in Matrix

## Problem Statement

Given a `M × N` matrix, find the maximum sum path from any cell in the first row to any cell in the last row. You can move to three cells from current cell (i,j): (i+1,j-1), (i+1,j), or (i+1,j+1).

**Example 1:**
```
Input: matrix = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]
Output: 18
```

Explanation:
> Path: 3 → 6 → 9 = 18
> This is the maximum sum path from first row to last row.

**Example 2:**
```
Input: matrix = [[10,10,2],
                 [5,100,1],
                 [50,10,10]]
Output: 160
```

Explanation:
> Path: 10 → 100 → 50 = 160
> Can move diagonally left, straight down, or diagonally right.

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At each cell in row i, we can reach it from three cells in row i-1: (i-1,j-1), (i-1,j), or (i-1,j+1). The maximum path sum to current cell = current value + max of three previous cells.

**Recurrence Relation:**
```
f(i,j) = matrix[i][j]                                           if i = 0
f(i,j) = -∞                                                     if j < 0 or j >= N
f(i,j) = matrix[i][j] + max(f(i-1,j-1), f(i-1,j), f(i-1,j+1))  otherwise
```

**Algorithm:**
1. Base case: If at first row, return matrix[0][j]
2. Base case: If out of bounds, return -infinity
3. Recursively compute: current + max(from three previous cells)
4. Try all columns in last row, return maximum

### Time Complexity: O(3^M)
**Why exponential?**
- At each cell, we make 3 recursive calls (diagonal-left, up, diagonal-right)
- Maximum depth of recursion tree = M (number of rows)
- Total nodes in tree ≈ 3^M
- Example: 5 rows → 3^5 = 243 calls per starting column

**Detailed breakdown:**
- Each cell (i,j) is computed multiple times
- f(2,1) might be called from f(3,0), f(3,1), and f(3,2)
- Overlapping subproblems cause redundant calculations
- No memoization = recompute same cells exponentially

### Space Complexity: O(M)
**Why?**
- Recursion stack depth = number of rows = M
- No additional data structures used

**Problem:** Too slow for large matrices due to repeated calculations.

> **Key Insight for Improvement:**
> We're computing the same subproblems repeatedly. If we store (memoize) results of f(i,j), we can avoid recomputation and reduce time from exponential to polynomial.

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Store results of each subproblem in a memo table. When we need f(i,j) again, return the stored value instead of recomputing.

**Recurrence Relation:**
```
Same as recursive, but check memo first:
if (i,j) in memo: return memo[i,j]
else: compute, store in memo, return
```

**Algorithm:**
1. Create memo dictionary/array
2. Before computing f(i,j), check if already in memo
3. If yes, return stored value
4. If no, compute recursively, store result, return
5. Try all columns in last row, return maximum

### Time Complexity: O(M×N)
**Why linear in matrix size?**
- Total unique subproblems = M×N (one per cell)
- Each subproblem computed exactly once
- Subsequent calls return memoized value in O(1)
- Total work = M×N × O(1) = O(M×N)

**Detailed breakdown:**
- First call to f(i,j): compute and store → O(1) work
- All future calls to f(i,j): return memo[i,j] → O(1) work
- Total cells = M×N
- Total time = M×N × O(1) = O(M×N)

**Improvement:** From O(3^M) to O(M×N)
- Example: 10×10 matrix
- Recursive: 3^10 ≈ 59,000 operations per column
- Memoization: 10×10 = 100 operations total

### Space Complexity: O(M×N)
**Why?**
- Memo table: M×N entries → O(M×N)
- Recursion stack: O(M) depth
- Total: O(M×N) + O(M) = O(M×N) (dominant term)

**Breakdown:**
- Memo storage: Each of M×N cells needs one entry
- Stack space: Maximum M recursive calls active
- Since M×N > M, space is O(M×N)

> **Key Insight for Improvement:**
> Memoization works but uses recursion (stack overhead). Can we solve iteratively from base cases upward? Yes - tabulation builds solution bottom-up without recursion.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Build solution iteratively from first row to last row. Fill dp table row by row, considering three possible previous cells for each current cell.

**DP State:**
```
dp[i][j] = maximum path sum to reach cell (i,j) from any cell in first row
```

**Transition:**
```
dp[i][j] = matrix[i][j] + max(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])
(handle boundary conditions for j-1 and j+1)
```

**Algorithm:**
1. Create dp table M×N
2. Initialize first row: dp[0][j] = matrix[0][j]
3. For each row i from 1 to M-1:
   - For each column j:
     - up = dp[i-1][j]
     - leftDiag = dp[i-1][j-1] if j > 0 else -∞
     - rightDiag = dp[i-1][j+1] if j < N-1 else -∞
     - dp[i][j] = matrix[i][j] + max(up, leftDiag, rightDiag)
4. Return max(dp[M-1])

### Time Complexity: O(M×N)
**Why?**
- Nested loops: outer loop M iterations, inner loop N iterations
- Each cell computed once: O(1) work per cell
- Total: M × N × O(1) = O(M×N)

**Detailed breakdown:**
- Initialize first row: O(N)
- Fill remaining rows: (M-1)×N ≈ O(M×N)
- Find maximum in last row: O(N)
- Total: O(N) + O(M×N) + O(N) = O(M×N)

**Comparison with Memoization:**
- Same time complexity: O(M×N)
- But no recursion overhead (no function call stack)
- Iterative approach is typically faster in practice

### Space Complexity: O(M×N)
**Why?**
- DP table: M×N entries → O(M×N)
- No recursion stack (iterative)
- Total: O(M×N)

**Breakdown:**
- dp array: M rows × N columns = M×N space
- Auxiliary variables: O(1)
- Total: O(M×N)

> **Key Insight for Improvement:**
> Notice that dp[i][j] only depends on dp[i-1][j-1], dp[i-1][j], and dp[i-1][j+1]. We don't need the entire table - just the previous row! This leads to space optimization.

<br>

---

## Solution 4: Space Optimized (One Row)

**Intuition:**
Use a single array prev[N] to store previous row values. For each new row, compute curr[N] using prev, then update prev = curr.

**Algorithm:**
1. Create array prev[N], initialize with first row
2. For each row i from 1 to M-1:
   - Create array curr[N]
   - For each column j:
     - up = prev[j]
     - leftDiag = prev[j-1] if j > 0 else -∞
     - rightDiag = prev[j+1] if j < N-1 else -∞
     - curr[j] = matrix[i][j] + max(up, leftDiag, rightDiag)
   - prev = curr
3. Return max(prev)

### Time Complexity: O(M×N)
**Why unchanged?**
- Same iteration pattern
- Each cell processed once
- Space optimization doesn't affect time

### Space Complexity: O(N)
**Why optimal?**
- Two arrays of size N (prev and curr): 2N → O(N)
- Few variables: O(1)
- Total: O(N)

**Improvement:**
- Before (tabulation): O(M×N)
- After (1D): O(N)
- Example: 1000×1000 matrix
  - Before: 1,000,000 space
  - After: 2,000 space (500× reduction!)

**Why this works:**
- When computing row i, we only need row i-1
- After processing row i, row i-1 is no longer needed
- So we can discard old rows and keep only current and previous

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(3^M) | O(M) | Baseline - too slow |
| Memoization | O(M×N) | O(M×N) | Cache results - exponential to polynomial |
| Tabulation | O(M×N) | O(M×N) | Remove recursion - same complexity, faster |
| Space Optimized | O(M×N) | O(N) | Keep only previous row - space reduced |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Recursion overhead → iterative approach
3. **Tabulation → Space Optimized:** Only need previous row → two arrays suffice

**When to use each:**
- **Memoization:** When not all subproblems needed, natural recursion
- **Tabulation:** When all subproblems needed, want iterative solution
- **Space Optimized:** When memory is constrained, optimal solution

> **Final Complexity:** O(M×N) time, O(N) space

<br>
<br>

---

```code```
