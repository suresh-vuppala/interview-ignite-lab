## Problem
Remove all occurrences of a given value from array in-place. Return new length.

## Approach
Two pointers: write pointer for valid elements, read pointer for scanning.

## Algorithm
1. Initialize write pointer at 0
2. Scan with read pointer
3. If element != target, copy to write position and increment write pointer
4. Return write pointer value

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```