## Heaps — Efficient Min/Max Extraction

A heap is a complete binary tree where every parent is smaller (min-heap) or larger (max-heap) than its children. The **priority queue** abstract data type is implemented using a heap.

<br>

## When to Use a Heap

Look for these signals in the problem:

- "Find the **Kth largest/smallest**" → Min/max heap of size K
- "**Merge K sorted** lists/arrays" → Min-heap of K elements
- "**Top K** frequent/closest" → Heap of size K
- "**Median** of a stream" → Two heaps (max-heap + min-heap)
- "**Schedule** to minimize/maximize" → Priority queue for greedy selection

<br>

## Heap Operations

| Operation | Time |
|-----------|------|
| Insert | O(log n) |
| Extract min/max | O(log n) |
| Peek min/max | O(1) |
| Build heap from array | O(n) |
| Heap sort | O(n log n) |

<br>

## Two-Heap Pattern (Median Finding)

Maintain a **max-heap** for the smaller half and a **min-heap** for the larger half. The median is always at the top of one (or average of both tops). This is a **Google/Meta favorite**.

<br>


## All Possible Edge Cases
1. **N/A — introductory overview**
