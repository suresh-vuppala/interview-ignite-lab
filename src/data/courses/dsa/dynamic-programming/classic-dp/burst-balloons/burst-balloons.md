# Burst Balloons

## Problem Statement
Solve Burst Balloons using dynamic programming.

## Approach

### DP Formula
```
dp[i][j] = max(dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j])
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
