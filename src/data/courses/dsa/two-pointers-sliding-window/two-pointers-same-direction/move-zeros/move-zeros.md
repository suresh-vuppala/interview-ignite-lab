## Problem
Move all zeros to the end of array while maintaining relative order of non-zero elements.

## Approach
Use two pointers: one for non-zero position, one for scanning.

## Algorithm
1. Initialize write pointer at 0
2. Scan array with read pointer
3. When non-zero element found, swap with write pointer position
4. Increment write pointer after swap

## Time Complexity
O(n) - single pass

## Space Complexity
O(1) - in-place

## Code
```code```