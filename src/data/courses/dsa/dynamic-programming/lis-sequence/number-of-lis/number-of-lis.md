## Problem Statement
Solve Number of LIS using dynamic programming.

## Approach

### DP Formula
```
count[i] = sum of count[j] where dp[j]+1 == dp[i]
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
