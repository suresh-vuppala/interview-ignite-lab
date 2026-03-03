## Problem Statement
Solve Stock Buy Sell II using dynamic programming.

## Approach

### DP Formula
```
profit += max(0, price[i] - price[i-1])
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
