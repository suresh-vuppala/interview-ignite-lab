# House Robber

## Problem Statement
Solve House Robber using dynamic programming.

## Approach

### DP Formula
```
dp[i] = max(dp[i-1], nums[i] + dp[i-2])
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
