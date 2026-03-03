## Problem
Find minimum length subarray with sum ≥ target.

## Approach
Variable sliding window: expand right, shrink left when valid.

## Algorithm
1. Expand right, add to sum
2. While sum ≥ target, update minLen and shrink from left
3. Return minLen

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```