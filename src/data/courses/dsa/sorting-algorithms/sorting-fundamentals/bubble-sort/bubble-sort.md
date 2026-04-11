Sort an array using the Bubble Sort algorithm. Repeatedly step through the list, compare adjacent elements, and swap them if they're in the wrong order.

<br>

> Input:
> nums = [64, 34, 25, 12, 22, 11, 90]

> Output:
> [11, 12, 22, 25, 34, 64, 90]

> Explanation:
> Pass 1: [34, 25, 12, 22, 11, 64, 90] — 64 bubbles to position 5
> Pass 2: [25, 12, 22, 11, 34, 64, 90] — 34 bubbles to position 4
> Pass 3: [12, 22, 11, 25, 34, 64, 90] — 25 bubbles up
> ... continues until no swaps needed
> 
> **Key insight:** After each pass, the largest unsorted element "bubbles" to its correct position. Optimization: if no swaps in a pass, array is sorted.

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 10⁴`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Already sorted:** Optimized bubble sort detects in O(n)
2. **Reverse sorted:** Worst case — maximum swaps O(n²)
3. **Single element:** Already sorted
4. **Empty array:** Nothing to sort
5. **All same elements:** No swaps needed
6. **Two elements:** At most one swap
7. **Duplicates:** Stable sort preserves relative order

<br>

---

## Solution: Bubble Sort

**Algorithm:**
1. For i = 0 to n-2 (passes):
   - swapped = false
   - For j = 0 to n-i-2 (comparisons):
     - If arr[j] > arr[j+1]: swap, set swapped = true
   - If !swapped: break (already sorted — optimization)

**Properties:**
- **Stable:** Yes (equal elements maintain relative order)
- **In-place:** Yes (O(1) extra space)
- **Adaptive:** Yes (O(n) for nearly sorted with optimization)

<br>

### Time Complexity
- **Best:** O(n) — already sorted, single pass with no swaps
- **Average:** O(n²)
- **Worst:** O(n²) — reverse sorted

### Space Complexity: O(1) — in-place

<br>
<br>

---

```code```
