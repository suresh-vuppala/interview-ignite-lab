# Stability of Merge Sort

## Problem Statement
Understand and demonstrate that merge sort is a stable sorting algorithm.

## Concept
Merge sort is **stable** because equal elements maintain their relative order. During merge, when elements are equal, we take from the left array first.

**Time Complexity**: O(n log n)  
**Space Complexity**: O(n)

## Key Point
Use `<=` comparison (not `<`) to ensure stability.

## Code
```code```