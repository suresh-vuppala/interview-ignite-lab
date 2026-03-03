## Problem
Find two numbers in sorted array that add up to target.

## Approach
Two pointers from both ends, adjust based on sum comparison.

## Algorithm
1. Initialize left = 0, right = n-1
2. Calculate sum = arr[left] + arr[right]
3. If sum == target, return indices
4. If sum < target, increment left
5. If sum > target, decrement right

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```