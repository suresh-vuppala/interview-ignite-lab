## Problem Statement
Solve Stock with Cooldown using dynamic programming.

## Approach

### DP Formula
```
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])
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
