# Dungeon Game

## Problem Statement

The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of `M × N` rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (0) or contain magic orbs that increase the knight's health (positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

**Example 1:**
```
Input: dungeon = [[-2,-3,3],
                  [-5,-10,1],
                  [10,30,-5]]
Output: 7
```

Explanation:
> Initial health of 7:
> Path: (0,0) → (0,1) → (0,2) → (1,2) → (2,2)
> Health: 7 → 5 → 2 → 5 → 6 → 1
> Knight never drops to 0 or below.

**Example 2:**
```
Input: dungeon = [[0]]
Output: 1
```

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
Work backwards from bottom-right to top-left. At each cell, calculate the minimum health needed to reach the princess from that cell. The minimum health needed = (minimum health needed from next cell) - (current cell value), but must be at least 1.

**Recurrence Relation:**
```
f(i,j) = max(1, 1 - dungeon[i][j])                if i = M-1 and j = N-1
f(i,j) = ∞                                        if i >= M or j >= N
f(i,j) = max(1, min(f(i,j+1), f(i+1,j)) - dungeon[i][j])  otherwise
```

**Algorithm:**
1. Base case: If at princess cell (M-1,N-1), return max(1, 1 - dungeon[M-1][N-1])
2. Base case: If out of bounds, return infinity
3. Recursively compute: max(1, min(right, down) - current)

### Time Complexity: O(2^(M+N))
**Why exponential?**
- At each cell, we make 2 recursive calls (right and down)
- Maximum depth of recursion tree = M+N (path length)
- Total nodes in tree ≈ 2^(M+N)
- Example: 3×3 grid → 2^6 = 64 calls

**Detailed breakdown:**
- Each cell (i,j) is computed multiple times
- f(1,1) might be called from f(0,1) and f(1,0)
- Overlapping subproblems cause redundant calculations
- No memoization = recompute same cells exponentially

### Space Complexity: O(M+N)
**Why?**
- Recursion stack depth = longest path from (0,0) to (M-1,N-1)
- Maximum depth = M-1 downs + N-1 rights = M+N-2 ≈ O(M+N)
- No additional data structures used

**Problem:** Too slow for large dungeons due to repeated calculations.

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
Build solution iteratively from bottom-right to top-left. Fill dp table starting from princess cell, working backwards to knight's starting position.

**DP State:**
```
dp[i][j] = minimum health needed at cell (i,j) to reach princess
```

**Transition:**
```
dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
```

**Algorithm:**
1. Create dp table (M+1)×(N+1), initialize all to infinity
2. Set dp[M][N-1] = dp[M-1][N] = 1 (boundary conditions)
3. For each row i from M-1 down to 0:
   - For each column j from N-1 down to 0:
     - minHP = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]
     - dp[i][j] = max(1, minHP)
4. Return dp[0][0]

### Time Complexity: O(M×N)
**Why?**
- Nested loops: outer loop M iterations, inner loop N iterations
- Each cell computed once: O(1) work per cell
- Total: M × N × O(1) = O(M×N)

**Detailed breakdown:**
- Initialize table: O((M+1)×(N+1)) ≈ O(M×N)
- Fill cells: M×N iterations
- Total: O(M×N) + O(M×N) = O(M×N)

**Comparison with Memoization:**
- Same time complexity: O(M×N)
- But no recursion overhead (no function call stack)
- Iterative approach is typically faster in practice

### Space Complexity: O(M×N)
**Why?**
- DP table: (M+1)×(N+1) entries → O(M×N)
- No recursion stack (iterative)
- Total: O(M×N)

**Breakdown:**
- dp array: (M+1) rows × (N+1) columns ≈ M×N space
- Auxiliary variables: O(1)
- Total: O(M×N)

> **Key Insight for Improvement:**
> Notice that dp[i][j] only depends on dp[i+1][j] (cell below) and dp[i][j+1] (cell to right). We don't need the entire table - just the next row! This leads to space optimization.

<br>

---

## Solution 4: Space Optimized (One Row)

**Intuition:**
Use a single array dp[N+1]. When processing cell (i,j), dp[j] will be updated to contain the minimum health needed at (i,j). Process right-to-left so dp[j+1] is already computed for current row.

**Algorithm:**
1. Create single array dp[N+1], initialize all to infinity
2. Set dp[N-1] = 1
3. For each row i from M-1 down to 0:
   - For each column j from N-1 down to 0:
     - minHP = min(dp[j], dp[j+1]) - dungeon[i][j]
     - dp[j] = max(1, minHP)
4. Return dp[0]

### Time Complexity: O(M×N)
**Why unchanged?**
- Same iteration pattern
- Each cell processed once
- In-place update doesn't change time

### Space Complexity: O(N)
**Why optimal?**
- Single array: dp[N+1] → O(N)
- Few variables: O(1)
- Total: O(N)

**Improvement:**
- Before (tabulation): O(M×N)
- After (1D): O(N)
- Example: 1000×1000 grid
  - Before: 1,000,000 space
  - After: 1,001 space (≈1000× reduction!)

**Why this works:**
- When at position (i,j):
  - dp[j] holds value from row i+1 (not yet overwritten for row i)
  - dp[j+1] already updated for row i (processed right-to-left)
  - So min(dp[j], dp[j+1]) correctly gets minimum from below and right

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^(M+N)) | O(M+N) | Baseline - too slow |
| Memoization | O(M×N) | O(M×N) | Cache results - exponential to polynomial |
| Tabulation | O(M×N) | O(M×N) | Remove recursion - same complexity, faster |
| Space Optimized | O(M×N) | O(N) | In-place update - optimal space |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Recursion overhead → iterative approach
3. **Tabulation → Space Optimized:** Only need next row → single array suffices
4. **Reverse DP:** Work backwards from destination to source for health calculation

**When to use each:**
- **Memoization:** When not all subproblems needed, natural recursion
- **Tabulation:** When all subproblems needed, want iterative solution
- **Space Optimized:** When memory is constrained, optimal solution

> **Final Complexity:** O(M×N) time, O(N) space

<br>
<br>

---

```code```
