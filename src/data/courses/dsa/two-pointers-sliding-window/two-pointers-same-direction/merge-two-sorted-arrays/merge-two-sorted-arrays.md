## Problem
Merge nums2 into nums1 (which has enough space). Both sorted.

## Approach
Fill from end using three pointers to avoid overwriting.

## Algorithm
1. Start from end of both arrays
2. Compare elements and place larger at end of nums1
3. Move corresponding pointer
4. Copy remaining nums2 elements if any

## Time Complexity
O(m + n)

## Space Complexity
O(1)

## Code
```code```