Partition around pivot, recursively sort partitions.

<br>

> nums=[3,6,8,10,1,2,1] → [1,1,2,3,6,8,10]
>
> **Key insight:** Choose pivot, partition: elements < pivot go left, > pivot go right. Recurse on both halves.

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

## Solution 1: N/A — this IS quicksort

### Time Complexity: O(N²) worst case

> **Drawback:**
> Worst case with bad pivot (sorted array + first/last pivot).

> **Key Insight for Improvement:**
> Random pivot or median-of-3 gives O(N log N) expected. Hoare partition is more efficient than Lomuto.

<br>

---

## Solution 2: QuickSort (Optimal)

**Intuition:** Choose pivot, partition: elements < pivot go left, > pivot go right. Recurse on both halves.

**Algorithm:**
1. If lo ≥ hi → return
2. pivotIdx = partition(arr, lo, hi)
3. quickSort(arr, lo, pivotIdx-1)
4. quickSort(arr, pivotIdx+1, hi)

Partition (Lomuto):
- pivot = arr[hi], i = lo-1
- For j = lo to hi-1: if arr[j] < pivot → i++, swap(arr[i], arr[j])
- Swap arr[i+1] and arr[hi] → return i+1

### Time Complexity: O(N log N) average
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[3,6,8,10,1,2,1] pivot=1: partition→[1,1,|2|,10,6,8,3]
Recurse left [1,1], right [10,6,8,3]→...→sorted
```

### Space Complexity: O(log N) stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — this IS quicksort | O(N²) worst case | Varies | Baseline |
| QuickSort | O(N log N) average | O(log N) stack | Optimal approach |

**Recommended Solution:** QuickSort — O(N log N) average time.

**Key Insights:**
1. **In-place:** O(log N) extra space (stack only)
2. **Fastest in practice:** Cache-friendly, small constant factor
3. **Randomized pivot:** Avoids O(N²) worst case
4. **Not stable:** Partitioning changes relative order

<br><br>

---

```code```
