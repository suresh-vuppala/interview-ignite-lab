## Problem
Given sorted array (can have negatives), return sorted array of squares.

## Approach
Two pointers from both ends, compare absolute values, fill result from end.

## Algorithm
1. Initialize left = 0, right = n-1, result array
2. Fill result from end (index n-1 to 0)
3. Compare |nums[left]| vs |nums[right]|
4. Place larger square at current result position
5. Move corresponding pointer

## Time Complexity
O(n)

## Space Complexity
O(n) for result

## Code
```code```