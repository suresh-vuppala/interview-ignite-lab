# Edit Distance

## Problem Statement
Solve Edit Distance using dynamic programming.

## Approach

### DP Formula
```
dp[i][j] = 1 + min(insert, delete, replace)
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
