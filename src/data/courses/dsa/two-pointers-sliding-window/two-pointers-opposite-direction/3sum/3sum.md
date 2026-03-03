## Problem
Find all unique triplets that sum to zero.

## Approach
Sort array, fix one element, use two pointers for remaining two.

## Algorithm
1. Sort array
2. For each element i, use two pointers (i+1, n-1)
3. If sum == 0, add triplet, skip duplicates
4. If sum < 0, move left pointer
5. If sum > 0, move right pointer

## Time Complexity
O(n²)

## Space Complexity
O(1) excluding result

## Code
```code```