## Problem
Find two lines that form container with maximum water.

## Approach
Two pointers from ends, move pointer with smaller height.

## Algorithm
1. Initialize left = 0, right = n-1, maxArea = 0
2. Calculate area = min(height[l], height[r]) * (r - l)
3. Update maxArea
4. Move pointer with smaller height inward
5. Return maxArea

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```