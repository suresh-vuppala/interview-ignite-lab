Find the number of unique paths from top-left to bottom-right in an M×N grid with obstacles. You can only move right or down, and cells with obstacles (marked as 1) cannot be traversed.

<br>

> Input:
> obstacleGrid = [
>   [0,0,0],
>   [0,1,0],
>   [0,0,0]
> ]

> Output:
> 2

> Explanation:
> Two paths exist:
> 1. Right → Right → Down → Down
> 2. Down → Down → Right → Right
> The center cell (1,1) with obstacle blocks other paths.
> 
> **Key insight:** Obstacles make certain cells unreachable (ways = 0).

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

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At each cell, we can reach it from either the top cell or the left cell. The total ways to reach current cell = ways from top + ways from left. If there's an obstacle, ways = 0.

**Recurrence Relation:**
```
f(i,j) = 0                           if grid[i][j] = 1 (obstacle)
f(i,j) = 1                           if i = 0 and j = 0 (start)
f(i,j) = f(i-1,j) + f(i,j-1)         otherwise
```

**Algorithm:**
1. Base case: If out of bounds or obstacle, return 0
2. Base case: If at start (0,0), return 1
3. Recursively compute: ways from top + ways from left

### Time Complexity: O(2^(M+N))
**Why exponential?**
- At each cell, we make 2 recursive calls (top and left)
- Maximum depth of recursion tree = M+N (path length)
- Total nodes in tree ≈ 2^(M+N)
- Example: 3×3 grid → 2^6 = 64 calls

**Detailed breakdown:**
- Each cell (i,j) is computed multiple times
- f(1,1) might be called from f(1,2) and f(2,1)
- Overlapping subproblems cause redundant calculations
- No memoization = recompute same cells exponentially

### Space Complexity: O(M+N)
**Why?**
- Recursion stack depth = longest path from (0,0) to (M-1,N-1)
- Maximum depth = M-1 downs + N-1 rights = M+N-2 ≈ O(M+N)
- No additional data structures used

**Problem:** Too slow for large grids due to repeated calculations.

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
1. Create memo dictionary/array initialized with -1
2. Before computing f(i,j), check if already in memo
3. If yes, return stored value
4. If no, compute recursively, store result, return

### Time Complexity: O(M×N)
**Why linear in grid size?**
- Total unique subproblems = M×N (one per cell)
- Each subproblem computed exactly once
- Subsequent calls return memoized value in O(1)
- Total work = M×N × O(1) = O(M×N)

**Detailed breakdown:**
- First call to f(i,j): compute and store → O(1) work
- All future calls to f(i,j): return memo[i,j] → O(1) work
- Total cells = M×N
- Total time = M×N × O(1) = O(M×N)

**Improvement:** From O(2^(M+N)) to O(M×N)
- Example: 10×10 grid
- Recursive: 2^20 ≈ 1,000,000 operations
- Memoization: 10×10 = 100 operations

### Space Complexity: O(M×N)
**Why?**
- Memo table: M×N entries → O(M×N)
- Recursion stack: O(M+N) depth
- Total: O(M×N) + O(M+N) = O(M×N) (dominant term)

**Breakdown:**
- Memo storage: Each of M×N cells needs one entry
- Stack space: Maximum M+N recursive calls active
- Since M×N > M+N, space is O(M×N)

> **Key Insight for Improvement:**
> Memoization works but uses recursion (stack overhead). Can we solve iteratively from base cases upward? Yes - tabulation builds solution bottom-up without recursion.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Instead of recursing from (M-1,N-1) down to (0,0), build solution iteratively from (0,0) up to (M-1,N-1). Fill dp table row by row, left to right.

**DP State:**
```
dp[i][j] = number of ways to reach cell (i,j) from (0,0)
```

**Transition:**
```
dp[i][j] = 0                           if obstacleGrid[i][j] = 1
dp[i][j] = dp[i-1][j] + dp[i][j-1]    otherwise
```

**Algorithm:**
1. Create dp table M×N, initialize all to 0
2. Set dp[0][0] = 1 if no obstacle at start
3. Fill first row: dp[0][j] = dp[0][j-1] if no obstacle
4. Fill first column: dp[i][0] = dp[i-1][0] if no obstacle
5. Fill remaining cells: dp[i][j] = dp[i-1][j] + dp[i][j-1]
6. Return dp[M-1][N-1]

### Time Complexity: O(M×N)
**Why?**
- Nested loops: outer loop M iterations, inner loop N iterations
- Each cell computed once: O(1) work per cell
- Total: M × N × O(1) = O(M×N)

**Detailed breakdown:**
- Initialize table: O(M×N)
- Fill first row: O(N)
- Fill first column: O(M)
- Fill remaining: (M-1)×(N-1) ≈ O(M×N)
- Total: O(M×N) + O(N) + O(M) + O(M×N) = O(M×N)

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
> Notice that dp[i][j] only depends on dp[i-1][j] (cell above) and dp[i][j-1] (cell to left). We don't need the entire table - just the previous row! This leads to space optimization.

<br>

---

## Solution 4: Space Optimized (Two Rows)

**Intuition:**
Since dp[i][j] only needs values from row i-1 and current row i (up to column j-1), we can use just two arrays: `prev` (previous row) and `curr` (current row).

**Algorithm:**
1. Create two arrays: prev[N] and curr[N]
2. Initialize prev[0] = 1
3. For each row i:
   - For each column j:
     - curr[j] = prev[j] + curr[j-1] (if no obstacle)
   - Copy curr to prev for next iteration
4. Return prev[N-1]

### Time Complexity: O(M×N)
**Why unchanged?**
- Still process each cell once
- Same nested loop structure
- Space optimization doesn't affect time

### Space Complexity: O(2×N) = O(N)
**Why improved?**
- Two arrays of size N: prev[N] + curr[N] = 2N
- Constant space for variables: O(1)
- Total: O(2N) = O(N)

**Improvement:**
- Before: O(M×N) space
- After: O(N) space
- Example: 1000×1000 grid
  - Before: 1,000,000 space units
  - After: 2,000 space units (500× reduction!)

> **Key Insight for Improvement:**
> We're using two arrays but can we use just one? Yes! Update the same array in-place. When computing curr[j], we need prev[j] (above) and curr[j-1] (left). If we update left-to-right, curr[j-1] is already updated and prev[j] hasn't been overwritten yet!

<br>

---

## Solution 5: Space Optimized (One Row)

**Intuition:**
Use a single array dp[N]. When processing cell (i,j), dp[j] contains value from previous row (i-1,j). After updating, dp[j] contains value for current row (i,j). Update left-to-right so dp[j-1] is already updated for current row.

**Algorithm:**
1. Create single array dp[N]
2. Initialize dp[0] = 1
3. For each row i:
   - For each column j:
     - If obstacle: dp[j] = 0
     - Else: dp[j] = dp[j] + dp[j-1]
       - dp[j] (before update) = ways from above
       - dp[j-1] (already updated) = ways from left
4. Return dp[N-1]

### Time Complexity: O(M×N)
**Why unchanged?**
- Same iteration pattern
- Each cell processed once
- In-place update doesn't change time

### Space Complexity: O(N)
**Why optimal?**
- Single array: dp[N] → O(N)
- Few variables: O(1)
- Total: O(N)

**Improvement:**
- Before (tabulation): O(M×N)
- After (1D): O(N)
- Example: 1000×1000 grid
  - Before: 1,000,000 space
  - After: 1,000 space (1000× reduction!)

**Why this works:**
- When at position (i,j):
  - dp[j] still holds value from row i-1 (not yet overwritten)
  - dp[j-1] already updated for row i (processed left-to-right)
  - So dp[j] += dp[j-1] correctly computes dp[i][j]

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^(M+N)) | O(M+N) | Baseline - too slow |
| Memoization | O(M×N) | O(M×N) | Cache results - exponential to polynomial |
| Tabulation | O(M×N) | O(M×N) | Remove recursion - same complexity, faster |
| Two Rows | O(M×N) | O(N) | Keep only needed rows - space reduced |
| One Row | O(M×N) | O(N) | In-place update - optimal space |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Recursion overhead → iterative approach
3. **Tabulation → Two Rows:** Full table not needed → keep only previous row
4. **Two Rows → One Row:** Can update in-place → single array suffices

**When to use each:**
- **Memoization:** When not all subproblems needed, natural recursion
- **Tabulation:** When all subproblems needed, want iterative solution
- **Space Optimized:** When memory is constrained, optimal solution

> **Final Complexity:** O(M×N) time, O(N) space

<br>
<br>

---

```code```
