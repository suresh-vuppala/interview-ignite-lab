## Problem
Find longest subarray with at most 2 distinct elements.

## Approach
Sliding window with frequency map.

## Algorithm
1. Use map to track element frequencies
2. Expand right, add to map
3. If distinct > 2, shrink from left
4. Track maximum length

## Time Complexity
O(n)

## Space Complexity
O(1) - at most 3 elements in map

## Code
```code```