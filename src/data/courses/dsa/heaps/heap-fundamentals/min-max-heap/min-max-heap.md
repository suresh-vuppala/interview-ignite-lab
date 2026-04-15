Implement min-heap and max-heap with insert, extract-min/max, and peek operations.

<br>

> MinHeap: insert(5), insert(3), insert(7), extractMin()→3, peek()→5
>
> **Key insight:** Complete binary tree stored in array. Parent=i/2, children=2i,2i+1. Heapify up on insert, heapify down on extract.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵ operations
- -10⁹ ≤ values ≤ 10⁹ apply

<br>

---

## All Possible Edge Cases
1. **Extract from empty heap:** handle error
2. **Single element**
3. **All same values**
4. **Insert in sorted/reverse order**

<br>

---

## Solution 1: Unsorted array

**Intuition:**
The most straightforward approach. Finding min/max requires scanning entire array each time.

**Algorithm:**
1. Sort the input array
2. Iterate through the sorted array
3. Check the required condition at each step

### Time Complexity: O(N) extract, O(1) insert
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Finding min/max requires scanning entire array each time. O(N) per extraction.

> **Key Insight for Improvement:**
> Heap property: parent ≤ children (min-heap). Maintained via bubbling up (insert) and sifting down (extract). O(log N) per operation.

<br>

---

## Solution 2: Binary Heap (Optimal)

**Intuition:** Complete binary tree stored in array. Parent=i/2, children=2i,2i+1. Heapify up on insert, heapify down on extract.

**Algorithm:**
1. Insert: add at end, bubble up (swap with parent while smaller)
2. Extract: swap root with last, remove last, sift down (swap with smaller child)
3. Peek: return root — O(1)
4. Build heap: heapify from bottom — O(N)

### Time Complexity: O(log N) per op
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
Insert 5,3,7: arr=[3,5,7] (min-heap)
Extract min: swap 3↔7→arr=[7,5], sift 7 down→arr=[5,7]
Peek: 5
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Unsorted array | O(N) extract, O(1) insert | Varies | Baseline |
| Binary Heap | O(log N) per op | O(N) | Heap property: parent ≤ children (min-heap). Maintained via  |

**Recommended Solution:** Binary Heap — O(log N) per op time, O(N) space.

**Key Insights:**
1. **Array storage:** Parent=i/2, left=2i, right=2i+1 — no pointers needed
2. **Build heap is O(N):** Not O(N log N) — sift down from bottom is cheaper
3. **Foundation:** Priority queue, heap sort, Dijkstra, merge-k-sorted

<br>
<br>

---

```code```
