Knight starts at top-left, must reach bottom-right princess. Each cell adds/subtracts health. Find minimum initial health to survive (health > 0 always).

<br>

> dungeon=[[-2,-3,3],[-5,-10,1],[10,30,-5]] → 7
> **Key insight:** Work BACKWARDS from bottom-right. dp[i][j] = min health needed at (i,j). dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^(m+n))

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])`

<br>

---

## Solution 2: DP — Bottom-up from bottom-right

**Recurrence:** `dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])`

### Time Complexity: O(m×n)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(n)

**Example walkthrough:**
```
Work backwards: need ≥1 health at each cell. dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1])
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
