## Problem Statement
Solve 0/1 Knapsack using dynamic programming.

## Approach

### DP Formula
```
dp[i][w] = max(dp[i-1][w], val[i] + dp[i-1][w-wt[i]])
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
