## Problem
Calculate how much water can be trapped after raining.

## Approach
Two pointers with left_max and right_max tracking.

## Algorithm
1. Initialize left = 0, right = n-1
2. Track left_max and right_max
3. If height[left] < height[right], process left side
4. Otherwise process right side
5. Add trapped water based on max heights

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```