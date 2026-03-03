# Kth Smallest Element in Sorted Matrix

## Problem Statement

Find the kth smallest element in an n x n matrix where each row and column is sorted.

## Approach

- Use min heap with first element of each row
- Extract min k times
- Push next element from same row

## Complexity Analysis

### Time Complexity: O(k log n)
- k extractions
- Each O(log n)

### Space Complexity: O(n)

## Code

```code```