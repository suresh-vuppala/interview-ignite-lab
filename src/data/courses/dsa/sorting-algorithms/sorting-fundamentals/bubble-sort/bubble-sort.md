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

### Time Complexity: O(N²)

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
