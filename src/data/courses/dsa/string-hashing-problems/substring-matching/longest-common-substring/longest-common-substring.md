# Longest Common Substring

Find longest substring common to two strings.

## Approaches
1. DP: O(n*m)
2. Binary search + rolling hash: O(n log n)

## DP Formula
dp[i][j] = dp[i-1][j-1] + 1 if s1[i] == s2[j]

## Code
```code```