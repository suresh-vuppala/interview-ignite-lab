Classic heap problems: find kth largest in stream, sort a nearly-sorted array, merge k sorted arrays.

<br>

> Kth largest in stream: add(3), add(5), add(10), kthLargest(k=2)→5
>
> **Key insight:** Min-heap of size k for kth-largest (top = kth largest). Full sort of k-sorted array using min-heap of size k+1.

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Sort then index

**Intuition:**
The most straightforward approach. Full sorting is overkill when we only need the kth element or partial ordering.

**Algorithm:**
1. Sort the input array
2. Iterate through the sorted array
3. Check the required condition at each step

### Time Complexity: O(N log N)
**Why?**
Sorting or divide-and-conquer requires O(N log N).
Each of log N levels processes N elements.

**Detailed breakdown:**
For N=100,000: ~1.7 million operations — efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Full sorting is overkill when we only need the kth element or partial ordering.

> **Key Insight for Improvement:**
> Heap of size K: maintain only what's needed. Min-heap for kth-largest, max-heap for kth-smallest. Nearly-sorted: heap of size k+1.

<br>

---

## Solution 2: Size-K Heap (Optimal)

**Intuition:** Min-heap of size k for kth-largest (top = kth largest). Full sort of k-sorted array using min-heap of size k+1.

**Algorithm:**
1. Kth largest: min-heap size k. Push new element, if size > k pop min. Top = kth largest.
2. K-sorted array: min-heap of size k+1. Pop min, add next. Output is sorted.
3. Merge K sorted: min-heap of K elements (one per list). Pop min, push next from same list.

### Time Complexity: O(N log K)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
Kth largest (k=3): heap=[]. Add 4→[4]. Add 5→[4,5]. Add 8→[4,5,8].
Add 2→heap full, 2<4(top)→skip. Add 9→pop 4, push 9→[5,8,9]. 3rd largest=5
```

### Space Complexity: O(K)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort then index | O(N log N) | Varies | Baseline |
| Size-K Heap | O(N log K) | O(K) | Heap of size K: maintain only what's needed. Min-heap for kt |

**Recommended Solution:** Size-K Heap — O(N log K) time, O(K) space.

**Key Insights:**
1. **Size-K heap pattern:** Keep only K elements — O(N log K) vs O(N log N)
2. **Min-heap for kth-largest:** Counter-intuitive but correct — top IS the kth
3. **Nearly sorted optimization:** Only need window of k+1 elements

<br>
<br>

---

```code```
