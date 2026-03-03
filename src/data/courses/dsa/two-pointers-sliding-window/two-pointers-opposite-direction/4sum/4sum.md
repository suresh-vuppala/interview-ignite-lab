## Problem
Find all unique quadruplets that sum to target.

## Approach
Sort array, fix two elements, use two pointers for remaining two.

## Algorithm
1. Sort array
2. Fix first element i
3. Fix second element j (i+1 to n-2)
4. Use two pointers for remaining elements
5. Skip duplicates at all levels

## Time Complexity
O(n³)

## Space Complexity
O(1) excluding result

## Code
```code```