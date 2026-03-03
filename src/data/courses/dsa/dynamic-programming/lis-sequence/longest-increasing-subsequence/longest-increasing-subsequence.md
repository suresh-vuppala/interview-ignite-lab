## Problem Statement
Solve Longest Increasing Subsequence using dynamic programming.

## Approach

### DP Formula
```
dp[i] = max(dp[j] + 1) if arr[i] > arr[j]
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
