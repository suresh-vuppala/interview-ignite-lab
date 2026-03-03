## Common Heap Problems

### Top K Elements
- Use min/max heap of size k
- Maintain k largest or smallest elements

### Merge K Sorted Arrays
- Use min heap with one element from each array
- Extract min and add next from same array

### Running Median
- Two heaps: max heap for lower half, min heap for upper half
- Balance heaps to find median

## Problem Patterns

1. **Top K Pattern**: Min heap of size k for k largest, max heap for k smallest
2. **Merge Pattern**: Min heap to merge sorted sequences
3. **Two Heap Pattern**: Balance two heaps for median/percentile

## Complexity Analysis

Most heap problems: O(n log k) time, O(k) space

## Code

```code```
