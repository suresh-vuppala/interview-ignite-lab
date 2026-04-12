Find minimum sum path from top-left to bottom-right (move right or down).

<br>

> grid=[[1,3,1],[1,5,1],[4,2,1]] → 7 (1→3→1→1→1)
> **Key insight:** dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^(m+n))

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])`

<br>

---

## Solution 2: DP — Bottom-up 1D

**Recurrence:** `dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])`

### Time Complexity: O(m×n)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(n)

**Example walkthrough:**
```
Path: 1→3→1→1→1 = 7
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(2^(m+n)) | O(N) stack |
| Memoization | O(m×n) | Same as tabulation |
| Tabulation | O(m×n) | O(n) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
