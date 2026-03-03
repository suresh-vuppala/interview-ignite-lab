# Stock Buy Sell III

## Problem Statement
Solve Stock Buy Sell III using dynamic programming.

## Approach

### DP Formula
```
dp[k][i] = max(dp[k][i-1], price[i] + maxDiff)
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
