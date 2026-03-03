## Problem
Find length of longest subarray with sum ≤ K.

## Approach
Variable sliding window: expand right, shrink left when sum > K.

## Algorithm
1. Initialize left = 0, sum = 0, maxLen = 0
2. Expand right, add to sum
3. While sum > K, shrink from left
4. Update maxLen

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```