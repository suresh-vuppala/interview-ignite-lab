# Binary Strings No Consecutive 1s

## Problem Statement
Solve Binary Strings No Consecutive 1s using dynamic programming.

## Approach

### DP Formula
```
dp[i] = dp[i-1] + dp[i-2]
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
