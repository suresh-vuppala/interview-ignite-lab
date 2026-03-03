## Problem Statement
Sort an array using selection sort algorithm.

## Approach
Repeatedly find the minimum element from unsorted portion and place it at the beginning.

**Time Complexity**: O(n²) in all cases  
**Space Complexity**: O(1)  
**Stable**: No (can be made stable with modifications)

## Algorithm
1. Find minimum element in unsorted portion
2. Swap with first unsorted element
3. Move boundary of sorted portion
4. Repeat until array is sorted

## Characteristics
- **Minimum swaps**: Only n-1 swaps (good for expensive swap operations)
- **Not adaptive**: Always O(n²) even if sorted
- **Unstable**: Relative order of equal elements may change

## Code
```code```