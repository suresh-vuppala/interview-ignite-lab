Insert each element into its correct position in the sorted prefix.

<br>

> nums=[5,3,1,4,2] → [1,2,3,4,5]
>
> **Key insight:** For each element, shift larger elements right and insert at correct position. Like sorting playing cards.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁴

<br>

---

## All Possible Edge Cases
1. **Nearly sorted:** O(N) — best case for insertion sort
2. **Reverse sorted:** worst case O(N²)
3. **All equal**

<br>

---

## Solution 1: N/A — this IS insertion sort

**Intuition:**
The most straightforward approach. Quadratic for reverse-sorted input.

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
> Quadratic for reverse-sorted input. O(N) for nearly sorted.

> **Key Insight for Improvement:**
> Best for small arrays and nearly-sorted data. O(N) best case.

<br>

---

## Solution 2: Insertion Sort (Optimal)

**Intuition:** For each element, shift larger elements right and insert at correct position. Like sorting playing cards.

**Algorithm:**
1. For i = 1 to N-1:
   - key = arr[i], j = i-1
   - While j ≥ 0 and arr[j] > key: arr[j+1] = arr[j], j--
   - arr[j+1] = key

### Time Complexity: O(N²) worst, O(N) best
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[5,3,1,4,2]: insert 3→[3,5,...], insert 1→[1,3,5,...], insert 4→[1,3,4,5,...], insert 2→[1,2,3,4,5]
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — this IS insertion sort | O(N²) | Varies | Baseline |
| Insertion Sort | O(N²) worst, O(N) best | O(1) | Optimal approach |

**Recommended Solution:** Insertion Sort — O(N²) worst, O(N) best time.

**Key Insights:**
1. **O(N) for nearly sorted:** Few shifts needed
2. **Stable:** Equal elements maintain order
3. **Best for small N:** Used as base case in TimSort and IntroSort

<br><br>

---

```code```
