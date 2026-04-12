Same as unique paths but with obstacles (grid[i][j]=1 means blocked).

<br>

> grid=[[0,0,0],[0,1,0],[0,0,0]] → 2
> **Key insight:** Same recurrence but dp[i][j]=0 if obstacle. Obstacle blocks all paths through that cell.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^(m+n))

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[i][j] = 0 if obstacle, else dp[i-1][j] + dp[i][j-1]`

<br>

---

## Solution 2: DP — Bottom-up with obstacle check

**Recurrence:** `dp[i][j] = 0 if obstacle, else dp[i-1][j] + dp[i][j-1]`

### Time Complexity: O(m×n)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(n)

**Example walkthrough:**
```
3×3 with obstacle at (1,1): only 2 paths around it
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
