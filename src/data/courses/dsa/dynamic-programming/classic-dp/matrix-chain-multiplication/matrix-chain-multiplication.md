## Problem Statement
Solve Matrix Chain Multiplication using dynamic programming.

## Approach

### DP Formula
```
dp[i][j] = min(dp[i][k] + dp[k+1][j] + cost)
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
