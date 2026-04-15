## Sorting — Organizing Data Efficiently

Sorting is one of the most fundamental operations in computer science. Understanding sorting algorithms gives you insight into **divide and conquer**, **recursion**, **time-space tradeoffs**, and forms the basis for techniques like binary search and two pointers.

<br>

## Why Learn Sorting?

- **Prerequisite** for binary search, two pointers, and many greedy algorithms
- **Interview staple** — "Implement quick sort" or "Sort this under these constraints" is common
- **QuickSelect** — O(n) average selection algorithm, asked frequently at Google
- **Understanding tradeoffs** — stable vs unstable, in-place vs extra space, best/worst case

<br>

## Sorting Algorithms Comparison

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | ❌ |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n)* | ❌ |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ |

<br>

*\* Quick Sort space is O(log n) average (recursion stack), O(n) worst case with skewed partitions.*

## What You'll Master

1. **O(n²) sorts** — Bubble, Selection, Insertion (know them, don't use them in interviews)
2. **Merge Sort** — Divide and conquer, stable, O(n log n) guaranteed, great for linked lists
3. **Quick Sort** — In-place, average O(n log n), pivot selection matters
4. **QuickSelect** — Find kth element in O(n) average — very common in interviews
5. **Applications** — Count Inversions, Sort Linked List

<br>


## All Possible Edge Cases
1. **N/A — introductory overview**
