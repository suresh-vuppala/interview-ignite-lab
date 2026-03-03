## Problem
Given a sorted array, remove duplicates in-place such that each element appears only once. Return the new length.

## Approach
Use two pointers: one for reading and one for writing unique elements.

## Algorithm
1. If array is empty, return 0
2. Initialize write pointer at index 0
3. Iterate with read pointer from index 1
4. If current element differs from element at write pointer, increment write pointer and copy element
5. Return write pointer + 1

## Time Complexity
O(n) - single pass through array

## Space Complexity
O(1) - in-place modification

## Code
```code```