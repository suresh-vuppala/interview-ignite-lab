## Problem Statement
Solve Integer Break using dynamic programming.

## Approach

### DP Formula
```
dp[i] = max(j * (i-j), j * dp[i-j])
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
