## Problem Statement
Solve Distinct Subsequences using dynamic programming.

## Approach

### DP Formula
```
dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
```

### Steps
1. Define DP state
2. Initialize base cases
3. Fill DP table using recurrence
4. Return final result

## Complexity
- Time: O(n) or O(n²)
- Space: O(n)

```code```
