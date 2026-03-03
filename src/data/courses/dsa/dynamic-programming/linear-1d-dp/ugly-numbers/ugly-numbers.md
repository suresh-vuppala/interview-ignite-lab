# Ugly Numbers

## Problem Statement
Solve Ugly Numbers using dynamic programming.

## Approach

### DP Formula
```
dp[i] = min(dp[i2]*2, dp[i3]*3, dp[i5]*5)
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
