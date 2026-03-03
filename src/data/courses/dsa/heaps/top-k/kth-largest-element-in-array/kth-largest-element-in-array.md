# Kth Largest Element in Array

## Problem Statement

Find the kth largest element in an unsorted array.

## Approach

### Min Heap Approach
- Maintain min heap of size k
- Keep k largest elements
- Root is kth largest

### Quick Select
- Partition like quicksort
- Average O(n), worst O(n²)

## Complexity Analysis

### Time Complexity: O(n log k)
- Process n elements
- Each heap operation O(log k)

### Space Complexity: O(k)

## Code

```code```