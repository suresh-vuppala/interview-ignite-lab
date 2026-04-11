# Cherry Pickup

## Problem Statement

You are given an `N × N` grid representing a field of cherries, each cell is one of three possible integers:
- `0` means the cell is empty, so you can pass through
- `1` means the cell contains a cherry that you can pick up and pass through
- `-1` means the cell contains a thorn that blocks your way

Return the maximum number of cherries you can collect by following the rules below:
- Starting at position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells
- After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells
- When passing through a cell containing a cherry, you pick it up, and the cell becomes an empty cell (0)
- If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected

**Example 1:**
```
Input: grid = [[0,1,-1],
               [1,0,-1],
               [1,1,1]]
Output: 5
```

Explanation:
> Path 1: (0,0) → (1,0) → (2,0) → (2,1) → (2,2) = 3 cherries
> Path 2: (2,2) → (2,1) → (1,1) → (0,1) → (0,0) = 2 cherries
> Total: 5 cherries

**Example 2:**
```
Input: grid = [[1,1,-1],
               [1,-1,1],
               [-1,1,1]]
Output: 0
```

Explanation:
> No valid path exists from (0,0) to (2,2).

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
Instead of two separate trips, think of two people walking simultaneously from (0,0) to (N-1,N-1). At each step, both can move right or down. If they're at the same cell, count cherries only once.

**Key Observation:**
- Person 1 at (r1, c1), Person 2 at (r2, c2)
- If r1 + c1 = r2 + c2, they're at the same "step" (diagonal level)
- So we can represent state as (r1, c1, r2) where c2 = r1 + c1 - r2

**Recurrence Relation:**
```
f(r1,c1,r2) = -∞                                    if out of bounds or thorn
f(r1,c1,r2) = grid[r1][c1]                         if r1 = N-1 and c1 = N-1
f(r1,c1,r2) = cherries + max of 4 transitions      otherwise

cherries = grid[r1][c1] + (grid[r2][c2] if r1 ≠ r2 else 0)
4 transitions: both down, both right, p1 down + p2 right, p1 right + p2 down
```

**Algorithm:**
1. Base case: If out of bounds or thorn, return -infinity
2. Base case: If both at (N-1,N-1), return grid[N-1][N-1]
3. Count cherries at current cells (once if same cell)
4. Try all 4 combinations of moves, take maximum
5. Return max(0, result) since we can choose not to go if no valid path

### Time Complexity: O(4^N)
**Why exponential?**
- At each state, we make 4 recursive calls (4 move combinations)
- Maximum depth of recursion tree = 2N-2 (steps to reach bottom-right)
- Total nodes in tree ≈ 4^(2N)
- Example: 3×3 grid → 4^4 = 256 calls

**Detailed breakdown:**
- Each state (r1,c1,r2) is computed multiple times
- Overlapping subproblems cause redundant calculations
- No memoization = recompute same states exponentially

### Space Complexity: O(N)
**Why?**
- Recursion stack depth = 2N-2 (number of steps)
- No additional data structures used

**Problem:** Too slow for even small grids due to repeated calculations.

> **Key Insight for Improvement:**
> We're computing the same subproblems repeatedly. If we store (memoize) results of f(r1,c1,r2), we can avoid recomputation and reduce time from exponential to polynomial.

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Store results of each subproblem in a 3D memo table. When we need f(r1,c1,r2) again, return the stored value instead of recomputing.

**Recurrence Relation:**
```
Same as recursive, but check memo first:
if (r1,c1,r2) in memo: return memo[r1,c1,r2]
else: compute, store in memo, return
```

**Algorithm:**
1. Create 3D memo dictionary/array
2. Before computing f(r1,c1,r2), check if already in memo
3. If yes, return stored value
4. If no, compute recursively, store result, return

### Time Complexity: O(N³)
**Why cubic?**
- Total unique subproblems = N × N × N (three dimensions)
- Each subproblem computed exactly once
- Subsequent calls return memoized value in O(1)
- Total work = N³ × O(1) = O(N³)

**Detailed breakdown:**
- r1 can be 0 to N-1: N values
- c1 can be 0 to N-1: N values
- r2 can be 0 to N-1: N values
- Total states = N × N × N = N³

**Improvement:** From O(4^N) to O(N³)
- Example: 5×5 grid
- Recursive: 4^8 = 65,536 operations
- Memoization: 5³ = 125 operations

### Space Complexity: O(N³)
**Why?**
- Memo table: N³ entries → O(N³)
- Recursion stack: O(N) depth
- Total: O(N³) + O(N) = O(N³) (dominant term)

**Breakdown:**
- Memo storage: N × N × N cells need entries
- Stack space: Maximum 2N recursive calls active
- Since N³ > N, space is O(N³)

> **Key Insight for Improvement:**
> Memoization works but uses recursion (stack overhead). Can we solve iteratively from base cases upward? Yes - tabulation builds solution bottom-up without recursion.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Build solution iteratively using 3D DP table. Process states in order such that when computing dp[r1][c1][r2], all required previous states are already computed.

**DP State:**
```
dp[r1][c1][r2] = maximum cherries collected with person 1 at (r1,c1) and person 2 at (r2,c2)
where c2 = r1 + c1 - r2
```

**Transition:**
```
For each state (r1,c1,r2):
  cherries = grid[r1][c1] + (grid[r2][c2] if r1 ≠ r2 else 0)
  dp[r1][c1][r2] = cherries + max(dp[pr1][pc1][pr2])
  where (pr1,pc1) and (pr2,pc2) are previous positions
```

**Algorithm:**
1. Create 3D dp table N×N×N, initialize all to -infinity
2. Set dp[0][0][0] = grid[0][0]
3. For each r1 from 0 to N-1:
   - For each c1 from 0 to N-1:
     - For each r2 from 0 to N-1:
       - Calculate c2 = r1 + c1 - r2
       - Skip if invalid or thorn
       - Count cherries at current positions
       - Try all 4 previous state combinations
       - Update dp[r1][c1][r2] with maximum
4. Return max(0, dp[N-1][N-1][N-1])

### Time Complexity: O(N³)
**Why?**
- Triple nested loops: N × N × N iterations
- Each state computed once: O(1) work per state
- Total: N³ × O(1) = O(N³)

**Detailed breakdown:**
- Initialize table: O(N³)
- Fill states: N³ iterations
- Total: O(N³) + O(N³) = O(N³)

**Comparison with Memoization:**
- Same time complexity: O(N³)
- But no recursion overhead (no function call stack)
- Iterative approach is typically faster in practice

### Space Complexity: O(N³)
**Why?**
- DP table: N³ entries → O(N³)
- No recursion stack (iterative)
- Total: O(N³)

**Breakdown:**
- dp array: N × N × N = N³ space
- Auxiliary variables: O(1)
- Total: O(N³)

**Note:** This is a 3D DP problem where space optimization is complex and typically not done in practice due to the intricate dependencies between states.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(4^N) | O(N) | Baseline - too slow |
| Memoization | O(N³) | O(N³) | Cache results - exponential to polynomial |
| Tabulation | O(N³) | O(N³) | Remove recursion - same complexity, faster |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Recursion overhead → iterative approach
3. **Two Simultaneous Paths:** Model as two people walking together instead of two separate trips
4. **3D State Space:** (r1, c1, r2) where c2 is derived from constraint r1+c1 = r2+c2

**Why 3D DP?**
- Need to track positions of both people simultaneously
- Can't solve as two independent 2D DP problems because:
  - Second path depends on cherries collected in first path
  - Modeling as simultaneous paths avoids this dependency

**When to use each:**
- **Memoization:** Natural recursion, easier to implement
- **Tabulation:** Want iterative solution, slightly faster
- **Space Optimization:** Not practical for this 3D DP problem

> **Final Complexity:** O(N³) time, O(N³) space

<br>
<br>

---

```code```
