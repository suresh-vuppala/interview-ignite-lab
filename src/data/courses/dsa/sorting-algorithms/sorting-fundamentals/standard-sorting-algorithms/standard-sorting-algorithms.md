# Standard Sorting Algorithms

## Overview
Understanding different sorting algorithms and their characteristics.

## Common Sorting Algorithms

### Comparison-Based Sorts
1. **Bubble Sort** - O(n²) - Simple, stable
2. **Insertion Sort** - O(n²) - Efficient for small/nearly sorted
3. **Selection Sort** - O(n²) - Unstable, minimal swaps
4. **Merge Sort** - O(n log n) - Stable, requires extra space
5. **Quick Sort** - O(n log n) avg - Fast, in-place
6. **Heap Sort** - O(n log n) - In-place, unstable

### Non-Comparison Sorts
1. **Counting Sort** - O(n + k) - For limited range
2. **Radix Sort** - O(d × n) - For integers
3. **Bucket Sort** - O(n + k) - For uniform distribution

## Comparison Table

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | No |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Heap | O(n log n) | O(n log n) | O(n log n) | O(1) | No |

## When to Use
- **Small arrays**: Insertion Sort
- **Nearly sorted**: Insertion Sort
- **Guaranteed O(n log n)**: Merge Sort or Heap Sort
- **Average case speed**: Quick Sort
- **Stability required**: Merge Sort or Insertion Sort
- **Limited range integers**: Counting Sort

## Code
```code```