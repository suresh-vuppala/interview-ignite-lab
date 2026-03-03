# Stock Buy Sell I

## Problem Statement
Solve Stock Buy Sell I using dynamic programming.

## Approach

### DP Formula
```
maxProfit = max(maxProfit, price[i] - minPrice)
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
