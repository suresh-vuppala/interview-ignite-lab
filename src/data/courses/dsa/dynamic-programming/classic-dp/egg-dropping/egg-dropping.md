## Problem Statement
Solve Egg Dropping Problem using dynamic programming.

## Approach

### DP Formula
```
dp[e][f] = 1 + max(dp[e-1][k-1], dp[e][f-k])
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
