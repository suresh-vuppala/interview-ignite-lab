## Overview

A heap is a complete binary tree that satisfies the heap property. In a max heap, parent nodes are greater than children. In a min heap, parent nodes are smaller than children.

## Key Concepts

### Heap Properties
- **Complete Binary Tree**: All levels filled except possibly the last
- **Heap Property**: Parent-child relationship maintained
- **Array Representation**: Parent at i, children at 2i+1 and 2i+2

### Operations
- **Insert**: Add element and bubble up - O(log n)
- **Extract**: Remove root and bubble down - O(log n)
- **Peek**: View root - O(1)
- **Heapify**: Build heap from array - O(n)

## Applications

- Priority queues
- Heap sort
- Finding kth largest/smallest
- Median maintenance

## Complexity Analysis

### Time Complexity
- Insert: O(log n)
- Extract: O(log n)
- Peek: O(1)
- Build heap: O(n)

### Space Complexity: O(n)

## Code

```code```
