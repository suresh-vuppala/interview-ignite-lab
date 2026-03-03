## Problem Statement
Solve Longest Palindromic Substring using dynamic programming.

## Approach

### DP Formula
```
dp[i][j] = true if s[i]==s[j] and dp[i+1][j-1]
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
