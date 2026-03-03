# House Robber III Tree

## Problem Statement
Solve House Robber III Tree using dynamic programming.

## Approach

### DP Formula
```
dp[node] = max(rob(node), rob(left) + rob(right))
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
