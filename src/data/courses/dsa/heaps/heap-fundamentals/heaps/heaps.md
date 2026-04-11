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


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Single element:** It is both min and max
2. **All same elements:** Heap operations trivial
3. **Already a valid heap:** No restructuring needed
4. **k = 1:** Find min/max directly
5. **k = n:** Need to process entire heap
6. **Negative values:** Min heap with negatives

<br>

## Complexity Analysis

### Time Complexity
- Insert: O(log n)
- Extract: O(log n)
- Peek: O(1)
- Build heap: O(n)

### Space Complexity: O(n)

## Code

```code```
