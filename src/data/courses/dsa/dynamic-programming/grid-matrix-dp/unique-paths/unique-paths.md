Count unique paths from top-left to bottom-right of an m×n grid. Can only move right or down.

<br>

> m=3, n=7 → 28
> **Key insight:** dp[i][j] = dp[i-1][j] + dp[i][j-1]. Can arrive from above or left.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^(m+n))

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[i][j] = dp[i-1][j] + dp[i][j-1]`

<br>

---

## Solution 2: DP — Bottom-up with 1D array

**Recurrence:** `dp[i][j] = dp[i-1][j] + dp[i][j-1]`

### Time Complexity: O(m×n)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(n)

**Example walkthrough:**
```
3×3: dp=[[1,1,1],[1,2,3],[1,3,6]] → 6
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
