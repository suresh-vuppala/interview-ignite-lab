# Count Inversions

## Problem Statement
Count the number of inversions in an array. An inversion is a pair (i, j) where i < j but arr[i] > arr[j].

## Approach
Use merge sort to count inversions during the merge step. When an element from the right half is smaller, it forms inversions with all remaining elements in the left half.

**Time Complexity**: O(n log n)  
**Space Complexity**: O(n)

## Algorithm
1. Divide array using merge sort
2. Count inversions when merging
3. Add inversions from left, right, and cross inversions

## Code
```code```