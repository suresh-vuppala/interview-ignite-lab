## Problem
Find minimum length subarray containing at least one duplicate.

## Approach
Sliding window with set to track seen elements.

## Algorithm
1. Use set to track elements in window
2. Expand right, add to set
3. If duplicate found, update minLen and shrink
4. Return minimum length

## Time Complexity
O(n)

## Space Complexity
O(n)

## Code
```code```