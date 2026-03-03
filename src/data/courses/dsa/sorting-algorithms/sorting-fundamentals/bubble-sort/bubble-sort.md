## Problem Statement
Sort an array using bubble sort algorithm.

## Approach
Repeatedly swap adjacent elements if they are in wrong order. After each pass, the largest element "bubbles up" to its correct position.

**Time Complexity**: O(n²)  
**Space Complexity**: O(1)  
**Stable**: Yes

## Algorithm
1. Compare adjacent elements
2. Swap if left > right
3. Repeat for n-1 passes
4. Optimize: stop if no swaps in a pass

## Optimization
Add a flag to detect if array is already sorted.

## Code
```code```