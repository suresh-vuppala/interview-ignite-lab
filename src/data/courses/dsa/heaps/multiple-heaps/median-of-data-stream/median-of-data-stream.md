## Problem Statement

Design a data structure that supports adding numbers and finding the median.

## Approach

- Use two heaps: max heap for lower half, min heap for upper half
- Balance heaps to keep sizes equal or differ by 1
- Median is root(s) of heap(s)

## Complexity Analysis

### Time Complexity
- Add: O(log n)
- Find median: O(1)

### Space Complexity: O(n)

## Code

```code```