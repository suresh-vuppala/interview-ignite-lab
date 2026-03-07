# Triangle - Minimum Path Sum

## Problem Statement

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.

**Example 1:**
```
Input: triangle = [[2],
                   [3,4],
                   [6,5,7],
                   [4,1,8,3]]
Output: 11
```

Explanation:
> Path: 2 → 3 → 5 → 1 = 11
> This is the minimum sum path from top to bottom.

**Example 2:**
```
Input: triangle = [[-10]]
Output: -10
```

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At each position (i,j), we can move to (i+1,j) or (i+1,j+1). The minimum path sum from current position = current value + min of two possible next positions.

**Recurrence Relation:**
```
f(i,j) = 0                                      if i = N (reached bottom)
f(i,j) = triangle[i][j] + min(f(i+1,j), f(i+1,j+1))  otherwise
```

**Algorithm:**
1. Base case: If reached bottom (i = N), return 0
2. Recursively compute: current + min(down, diagonal-right)
3. Start from (0,0)

### Time Complexity: O(2^N)
**Why exponential?**
- At each position, we make 2 recursive calls (down and diagonal-right)
- Maximum depth of recursion tree = N (number of rows)
- Total nodes in tree ≈ 2^N
- Example: 4 rows → 2^4 = 16 calls

**Detailed breakdown:**
- Each position (i,j) is computed multiple times
- f(1,0) might be called from f(0,0) and explored multiple times
- Overlapping subproblems cause redundant calculations
- No memoization = recompute same positions exponentially

### Space Complexity: O(N)
**Why?**
- Recursion stack depth = number of rows = N
- No additional data structures used

**Problem:** Too slow for large triangles due to repeated calculations.

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

### Time Complexity: O(N²)
**Why quadratic?**
- Total unique subproblems = 1 + 2 + 3 + ... + N = N(N+1)/2 ≈ N²
- Each subproblem computed exactly once
- Subsequent calls return memoized value in O(1)
- Total work = N² × O(1) = O(N²)

**Detailed breakdown:**
- Row 0: 1 cell
- Row 1: 2 cells
- Row 2: 3 cells
- ...
- Row N-1: N cells
- Total: 1+2+3+...+N = N²/2 ≈ O(N²)

**Improvement:** From O(2^N) to O(N²)
- Example: 10 rows
- Recursive: 2^10 = 1,024 operations
- Memoization: 10×11/2 = 55 operations

### Space Complexity: O(N²)
**Why?**
- Memo table: N² entries → O(N²)
- Recursion stack: O(N) depth
- Total: O(N²) + O(N) = O(N²) (dominant term)

**Breakdown:**
- Memo storage: Each of N² positions needs one entry
- Stack space: Maximum N recursive calls active
- Since N² > N, space is O(N²)

> **Key Insight for Improvement:**
> Memoization works but uses recursion (stack overhead). Can we solve iteratively from base cases upward? Yes - tabulation builds solution bottom-up without recursion.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Build solution iteratively from top to bottom. Fill dp table row by row, considering two possible previous positions for each current position.

**DP State:**
```
dp[i][j] = minimum path sum from (0,0) to (i,j)
```

**Transition:**
```
dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j])
(handle boundary conditions for j=0 and j=i)
```

**Algorithm:**
1. Create dp table (jagged array matching triangle structure)
2. Initialize dp[0][0] = triangle[0][0]
3. For each row i from 1 to N-1:
   - For each position j from 0 to i:
     - If j = 0: dp[i][j] = dp[i-1][0] + triangle[i][j]
     - Else if j = i: dp[i][j] = dp[i-1][i-1] + triangle[i][j]
     - Else: dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j])
4. Return min(dp[N-1])

### Time Complexity: O(N²)
**Why?**
- Nested loops: outer loop N iterations, inner loop varies (1, 2, 3, ..., N)
- Total iterations = 1 + 2 + 3 + ... + N = N²/2
- Each cell computed once: O(1) work per cell
- Total: N² × O(1) = O(N²)

**Detailed breakdown:**
- Initialize first row: O(1)
- Fill remaining rows: 2 + 3 + ... + N ≈ O(N²)
- Find minimum in last row: O(N)
- Total: O(1) + O(N²) + O(N) = O(N²)

**Comparison with Memoization:**
- Same time complexity: O(N²)
- But no recursion overhead (no function call stack)
- Iterative approach is typically faster in practice

### Space Complexity: O(N²)
**Why?**
- DP table: N² entries → O(N²)
- No recursion stack (iterative)
- Total: O(N²)

**Breakdown:**
- dp array: 1 + 2 + 3 + ... + N = N²/2 space
- Auxiliary variables: O(1)
- Total: O(N²)

> **Key Insight for Improvement:**
> Notice that dp[i][j] only depends on dp[i-1][j-1] and dp[i-1][j]. We don't need the entire table - just the previous row! Better yet, we can work bottom-up and use the last row as our starting point.

<br>

---

## Solution 4: Space Optimized (Bottom-Up with One Row)

**Intuition:**
Start from the bottom row and work upward. Use a single array dp[N] where dp[j] represents the minimum path sum from position (i,j) to the bottom. Update in-place as we move up.

**Algorithm:**
1. Create array dp[N], initialize with last row of triangle
2. For each row i from N-2 down to 0:
   - For each position j from 0 to i:
     - dp[j] = triangle[i][j] + min(dp[j], dp[j+1])
3. Return dp[0]

### Time Complexity: O(N²)
**Why unchanged?**
- Same iteration pattern
- Each cell processed once
- Space optimization doesn't affect time

### Space Complexity: O(N)
**Why optimal?**
- Single array: dp[N] → O(N)
- Few variables: O(1)
- Total: O(N)

**Improvement:**
- Before (tabulation): O(N²)
- After (1D): O(N)
- Example: 100 rows
  - Before: 100×101/2 = 5,050 space
  - After: 100 space (50× reduction!)

**Why this works:**
- When computing row i, we only need row i+1
- By going bottom-up, dp[j] and dp[j+1] are already computed for row i+1
- We can update dp[j] in-place for row i
- After processing all rows, dp[0] contains the answer

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^N) | O(N) | Baseline - too slow |
| Memoization | O(N²) | O(N²) | Cache results - exponential to polynomial |
| Tabulation | O(N²) | O(N²) | Remove recursion - same complexity, faster |
| Space Optimized | O(N²) | O(N) | Bottom-up with one row - space reduced |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Recursion overhead → iterative approach
3. **Tabulation → Space Optimized:** Bottom-up traversal → only need one row

**When to use each:**
- **Memoization:** When not all subproblems needed, natural recursion
- **Tabulation:** When all subproblems needed, want iterative solution
- **Space Optimized:** When memory is constrained, optimal solution

> **Final Complexity:** O(N²) time, O(N) space

<br>
<br>

---

```code```
