Sort by repeatedly swapping adjacent out-of-order elements.

<br>

> nums=[5,3,1,4,2] → [1,2,3,4,5]
>
> **Key insight:** Compare adjacent pairs, swap if needed. Repeat until no swaps. Largest element 'bubbles' to end each pass.

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

## Solution 1: N/A — this IS the brute force

**Intuition:**
The most straightforward approach. Always O(N²) comparisons in worst case.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

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
> Always O(N²) comparisons in worst case. Very slow for large inputs.

> **Key Insight for Improvement:**
> Already optimal for bubble sort. Better algorithms: merge sort O(N log N), quicksort O(N log N) avg.

<br>

---

## Solution 2: Bubble Sort (Optimal)

**Intuition:** Compare adjacent pairs, swap if needed. Repeat until no swaps. Largest element 'bubbles' to end each pass.

**Algorithm:**
1. For i = 0 to N-2:
   - swapped = false
   - For j = 0 to N-i-2: if arr[j] > arr[j+1] → swap, swapped=true
   - If !swapped → break (already sorted — early termination)
2. Array is now sorted

### Time Complexity: O(N²)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[5,3,1,4,2]: Pass 1→[3,1,4,2,5], Pass 2→[1,3,2,4,5], Pass 3→[1,2,3,4,5]
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — this IS the brute force | O(N²) | Varies | Baseline |
| Bubble Sort | O(N²) | O(1) | Optimal approach |

**Recommended Solution:** Bubble Sort — O(N²) time.

**Key Insights:**
1. **Early termination:** If no swaps in a pass → sorted
2. **Best case O(N):** Already sorted + early termination
3. **Stable sort:** Equal elements maintain relative order

<br><br>

---

```code```
