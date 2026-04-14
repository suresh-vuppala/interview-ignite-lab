Find minimum in unsorted portion, swap with front position.

<br>

> nums=[5,3,1,4,2] → [1,2,3,4,5]
>
> **Key insight:** For each position i, find minimum in [i..N-1] and swap with position i.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: N/A — this IS selection sort

**Intuition:**
The most straightforward approach. Always O(N²) regardless of input order.

**Algorithm:**
1. Sort the input array
2. Iterate through the sorted array
3. Check the required condition at each step

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Always O(N²) regardless of input order. No early termination possible.

> **Key Insight for Improvement:**
> Already optimal for selection sort. Better: merge sort, quicksort.

<br>

---

## Solution 2: Selection Sort (Optimal)

**Intuition:** For each position i, find minimum in [i..N-1] and swap with position i.

**Algorithm:**
1. For i = 0 to N-2:
   - minIdx = i
   - For j = i+1 to N-1: if arr[j] < arr[minIdx] → minIdx = j
   - Swap arr[i] and arr[minIdx]

### Time Complexity: O(N²)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[5,3,1,4,2]: min in [0..4]=1(idx2)→swap→[1,3,5,4,2], min in [1..4]=2(idx4)→[1,2,5,4,3]...
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — this IS selection sort | O(N²) | Varies | Baseline |
| Selection Sort | O(N²) | O(1) | Optimal approach |

**Recommended Solution:** Selection Sort — O(N²) time.

**Key Insights:**
1. **Minimum swaps:** Only N-1 swaps total (vs bubble's many swaps)
2. **Not stable:** Swap may change relative order of equals
3. **Always O(N²):** No early termination unlike bubble sort

<br><br>

---

```code```
