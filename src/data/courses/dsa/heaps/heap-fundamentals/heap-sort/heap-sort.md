Sort an array using a heap. Build max-heap, then repeatedly extract maximum to build sorted array from right to left.

<br>

> nums=[4,10,3,5,1] → [1,3,4,5,10]
>
> **Key insight:** Build max-heap in O(N). Extract max N times: swap root with end of unsorted portion, heapify down. In-place, O(N log N).

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

## Solution 1: Naive: extract min N times into new array

**Intuition:**
The most straightforward approach. Using extra array wastes O(N) space.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N log N) + O(N) space
**Why?**
Sorting or divide-and-conquer requires O(N log N).
Each of log N levels processes N elements.

**Detailed breakdown:**
For N=100,000: ~1.7 million operations — efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Using extra array wastes O(N) space. We can sort in-place.

> **Key Insight for Improvement:**
> In-place: build max-heap, swap root (max) with last unsorted element, shrink heap by 1, heapify down. No extra space needed.

<br>

---

## Solution 2: In-Place Heap Sort (Optimal)

**Intuition:** Build max-heap in O(N). Extract max N times: swap root with end of unsorted portion, heapify down. In-place, O(N log N).

**Algorithm:**
1. Build max-heap: heapify from i=N/2 down to 0 — O(N)
2. For i = N-1 down to 1:
   - Swap arr[0] (max) with arr[i]
   - Heapify down on arr[0..i-1]
3. Array is now sorted ascending

### Time Complexity: O(N log N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
[4,10,3,5,1] → Build max-heap: [10,5,3,4,1]
Swap 10↔1: [1,5,3,4,|10] → heapify: [5,4,3,1,|10]
Swap 5↔1: [1,4,3,|5,10] → heapify: [4,1,3,|5,10]
...→ [1,3,4,5,10] ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Naive: extract min N times into new array | O(N log N) + O(N) space | Varies | Baseline |
| In-Place Heap Sort | O(N log N) | O(1) | In-place: build max-heap, swap root (max) with last unsorted |

**Recommended Solution:** In-Place Heap Sort — O(N log N) time, O(1) space.

**Key Insights:**
1. **In-place:** O(1) extra space — better than merge sort's O(N)
2. **Not stable:** Equal elements may change relative order
3. **Guaranteed O(N log N):** Unlike quicksort's O(N²) worst case
4. **Build heap O(N):** Key optimization — heapify from bottom up

<br>
<br>

---

```code```
