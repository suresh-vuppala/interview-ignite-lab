## Problem Statement
Sort an array using insertion sort algorithm.

## Approach
Build sorted array one element at a time by inserting each element into its correct position in the sorted portion.

**Time Complexity**: O(n²) worst, O(n) best  
**Space Complexity**: O(1)  
**Stable**: Yes

## Algorithm
1. Start from second element
2. Compare with elements in sorted portion
3. Shift larger elements right
4. Insert element at correct position

## Best Use Case
- Small arrays (< 10-20 elements)
- Nearly sorted arrays
- Online sorting (elements arrive one at a time)

## Code
```code```