## Problem Statement
Solve Coin Change Minimum using dynamic programming.

## Approach

### DP Formula
```
dp[i] = 1 + min(dp[i-coin])
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
