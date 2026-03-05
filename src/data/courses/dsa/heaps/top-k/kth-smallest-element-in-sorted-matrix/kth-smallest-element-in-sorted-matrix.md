Find the kth smallest element in an n × n matrix where each row and column is sorted in ascending order.

<br>

> Input:
> matrix = [
>   [1,  5,  9],
>   [10, 11, 13],
>   [12, 13, 15]
> ], k = 8

> Output:
> 13

> Explanation:
> Elements in sorted order: [1, 5, 9, 10, 11, 12, 13, 13, 15]
> 8th smallest: 13
> 
> Min heap process:
> - Initial: Add first element of each row: heap = [(1,0,0), (10,1,0), (12,2,0)]
> - Extract (1,0,0), add (5,0,1): heap = [(5,0,1), (10,1,0), (12,2,0)]
> - Extract (5,0,1), add (9,0,2): heap = [(9,0,2), (10,1,0), (12,2,0)]
> - Extract (9,0,2): heap = [(10,1,0), (12,2,0)]
> - Extract (10,1,0), add (11,1,1): heap = [(11,1,1), (12,2,0)]
> - Extract (11,1,1), add (13,1,2): heap = [(12,2,0), (13,1,2)]
> - Extract (12,2,0), add (13,2,1): heap = [(13,1,2), (13,2,1)]
> - Extract (13,1,2): 8th element = 13
> 
> **Key insight:** Use min heap to merge n sorted rows efficiently.

<br>

---

## Solution: Min Heap with Row Pointers

**Algorithm:**
1. Add first element of each row to min heap (with row, col indices)
2. Extract min k times:
   - Pop smallest element
   - If it has next element in same row, add to heap
3. Return kth extracted element

**Key insight:** Treat each row as sorted list, merge using heap like merge k sorted lists.

```code```

<br>

### Time Complexity Analysis

**Overall: O(k log n)**
- n = number of rows
- k = target position

**Build Initial Heap: O(n log n)**
- Insert n elements (first of each row)
- Each insertion: O(log n)

**Extract K Times: O(k log n)**
- Extract min: O(log n)
- Insert next: O(log n)
- Repeat k times: k × O(log n)

**Why not sort all elements?**
- Sort all: O(n² log n²) = O(n² log n)
- Heap approach: O(k log n)
- When k << n², heap is much better
- Example: n=1000, k=10 → O(10 log 1000) vs O(1,000,000 log 1,000,000)

**Alternative: Binary Search**
- Binary search on value range
- Count elements ≤ mid
- Time: O(n log(max-min))
- Better when k is large

**Space Complexity: O(n)**
- Heap stores at most n elements
- One element per row

**Why this works?**
- Matrix rows are sorted
- Heap ensures we always pick globally smallest
- Similar to merging sorted lists

**Applications:**
- Database query optimization
- Merge sorted streams
- Top-K queries on sorted data

> **Time Complexity:** O(k log n) where n = rows, k = target
> **Space Complexity:** O(n) for heap

<br>
<br>

---