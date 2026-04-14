Find the median from a data stream. Support addNum and findMedian in O(log N) / O(1).

<br>

> addNum(1), addNum(2), findMedian()→1.5, addNum(3), findMedian()→2.0
>
> **Key insight:** Two heaps: max-heap for lower half, min-heap for upper half. Balance sizes (differ by at most 1). Median from tops.

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

## Solution 1: Sort on every query

**Intuition:**
The most straightforward approach. Re-sorting after every insertion is extremely wasteful.

**Algorithm:**
1. Sort the input array
2. Iterate through the sorted array
3. Check the required condition at each step

### Time Complexity: O(N log N) per findMedian
**Why?**
Sorting or divide-and-conquer requires O(N log N).
Each of log N levels processes N elements.

**Detailed breakdown:**
For N=100,000: ~1.7 million operations — efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Re-sorting after every insertion is extremely wasteful.

> **Key Insight for Improvement:**
> Max-heap (lower half) + Min-heap (upper half). Add to appropriate heap, rebalance if sizes differ by > 1. Median = top of larger heap (or average of both tops).

<br>

---

## Solution 2: Two Heaps (Optimal)

**Intuition:** Two heaps: max-heap for lower half, min-heap for upper half. Balance sizes (differ by at most 1). Median from tops.

**Algorithm:**
1. addNum(num):
   - Push to maxHeap (lower). Pop max → push to minHeap (upper)
   - If minHeap.size > maxHeap.size: pop min from upper → push to lower
2. findMedian():
   - If sizes equal: average of both tops
   - Else: top of larger (maxHeap)

### Time Complexity: O(log N) add, O(1) median
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
add(1): maxH=[1], minH=[]
add(2): maxH push 2→pop 2→minH=[2], maxH=[1]. Balanced.
median: (1+2)/2 = 1.5
add(3): maxH push 3→pop 3→minH=[2,3], minH bigger→pop 2→maxH=[2,1]
median: maxH.top = 2.0 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort on every query | O(N log N) per findMedian | Varies | Baseline |
| Two Heaps | O(log N) add, O(1) median | O(N) | Max-heap (lower half) + Min-heap (upper half). Add to approp |

**Recommended Solution:** Two Heaps — O(log N) add, O(1) median time, O(N) space.

**Key Insights:**
1. **Two heaps = sorted halves:** Max-heap has lower half, min-heap has upper half
2. **Tops are adjacent:** maxHeap.top ≤ minHeap.top always
3. **O(1) median:** Just read one or two heap tops
4. **FAANG design classic:** Tests heap + real-time data processing

<br>
<br>

---

```code```
