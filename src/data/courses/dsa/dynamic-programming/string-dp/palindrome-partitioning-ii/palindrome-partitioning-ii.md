# Palindrome Partitioning II

## Problem Statement
Solve Palindrome Partitioning II using dynamic programming.

## Approach

### DP Formula
```
dp[i] = min(dp[j] + 1) if s[j..i] is palindrome
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
