## Problem Statement
Sort large files that don't fit in memory using external merge sort.

## Approach
1. Divide file into chunks that fit in memory
2. Sort each chunk and write to disk
3. Merge sorted chunks using k-way merge

**Time Complexity**: O(n log n)  
**Space Complexity**: O(k) where k is number of chunks

## Algorithm
1. Read chunks, sort in memory, write to temp files
2. Use min-heap for k-way merge
3. Write final sorted output

## Code
```code```