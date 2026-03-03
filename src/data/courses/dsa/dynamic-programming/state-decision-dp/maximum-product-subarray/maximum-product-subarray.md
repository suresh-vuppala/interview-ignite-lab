# Maximum Product Subarray

## Problem Statement
Solve Maximum Product Subarray using dynamic programming.

## Approach

### DP Formula
```
maxProd = max(nums[i], maxProd*nums[i], minProd*nums[i])
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
