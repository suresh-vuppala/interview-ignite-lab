Find the Kth largest element in an unsorted array.

<br>

> nums=[3,2,1,5,6,4], k=2 → 5
>
> **Key insight:** QuickSelect: partition like quicksort but only recurse into the side containing k. O(N) average. Min-heap of size K: O(N log K).

<br>

---

## Constraints
- 1 ≤ K ≤ N ≤ 10⁵
- -10⁴ ≤ nums[i] ≤ 10⁴ apply

<br>

---

## All Possible Edge Cases
1. **K = 1:** maximum element
2. **K = N:** minimum element
3. **All elements equal**
4. **Duplicate values around Kth**

<br>

---

## Solution 1: Sort then index

**Intuition:**
The most straightforward approach. Full sorting to find a single element is overkill.

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
> Full sorting to find a single element is overkill.

> **Key Insight for Improvement:**
> QuickSelect: partition array. If pivot at position N-K → found! If pivot too right → recurse left. Too left → recurse right. O(N) average.

<br>

---

## Solution 2: QuickSelect / Min-Heap (Optimal)

**Intuition:** QuickSelect: partition like quicksort but only recurse into the side containing k. O(N) average. Min-heap of size K: O(N log K).

**Algorithm:**
1. QuickSelect: choose pivot, partition
   - If pivotIndex == N-K → return pivot
   - If pivotIndex < N-K → search right half
   - If pivotIndex > N-K → search left half
2. Min-heap alternative: push all, maintain size K. Top = Kth largest.

### Time Complexity: O(N) avg QuickSelect
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
nums=[3,2,1,5,6,4], k=2, target_idx=4
Partition around 4: [3,2,1,|4|,6,5] → pivotIdx=3
3 < 4 → search right: [6,5] → partition → 5 at idx 4 → Kth=5 ✓
```

### Space Complexity: O(1) QuickSelect

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort then index | O(N log N) | Varies | Baseline |
| QuickSelect / Min-Heap | O(N) avg QuickSelect | O(1) QuickSelect | QuickSelect: partition array. If pivot at position N-K → fou |

**Recommended Solution:** QuickSelect / Min-Heap — O(N) avg QuickSelect time, O(1) QuickSelect space.

**Key Insights:**
1. **QuickSelect = partial QuickSort:** Only recurse into one half → O(N) avg
2. **Worst case O(N²):** Random pivot or median-of-3 helps
3. **Min-heap alternative:** O(N log K) guaranteed, simpler to implement
4. **FAANG top-10:** Tests understanding of selection algorithms

<br>
<br>

---

```code```
