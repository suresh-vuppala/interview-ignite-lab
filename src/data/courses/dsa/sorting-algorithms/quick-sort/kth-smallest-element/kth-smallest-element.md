Find the kth smallest element in an unsorted array using QuickSelect algorithm.

<br>

> Input:
> arr = [7, 10, 4, 3, 20, 15], k = 3

> Output:
> 7

> Explanation:
> Sorted array would be [3, 4, 7, 10, 15, 20]
> The 3rd smallest element is 7
> 
> QuickSelect process:
> - Partition around pivot 15: [7, 10, 4, 3] + [15] + [20]
> - Pivot at index 4, k=3, so search left subarray
> - Partition [7, 10, 4, 3] around pivot 3: [3] + [7, 10, 4]
> - Pivot at index 0, k=3, so search right subarray
> - Continue until pivot index = k-1 = 2, return element at that position

<br>


---

## Constraints

- `1 ≤ k ≤ nums.length ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Find minimum element
2. **k = n:** Find maximum element
3. **All same elements:** Any element is the answer
4. **Already sorted:** Element at index k-1
5. **Single element, k=1:** Return that element
6. **Array with negatives:** Smallest can be very negative

<br>

---

## Solution: QuickSelect Algorithm

QuickSelect is an optimization of QuickSort for finding kth element:
1. Partition array around pivot
2. If pivot index == k-1, return pivot (found kth smallest)
3. If pivot index > k-1, recurse on left subarray
4. If pivot index < k-1, recurse on right subarray



<br>

### Time Complexity Analysis

**Average Case: O(n)**
- First partition: n comparisons
- Second partition: n/2 comparisons (on average, half the array)
- Third partition: n/4 comparisons
- Total: n + n/2 + n/4 + ... = n(1 + 1/2 + 1/4 + ...) = 2n = O(n)
- Unlike QuickSort, we only recurse on ONE side, not both

**Worst Case: O(n²)**
- Occurs when pivot is always smallest/largest element
- Must process n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = O(n²) elements
- Can be avoided with randomized pivot selection

**Best Case: O(n)**
- Occurs when pivot is always the median
- Same as average case

> **Time Complexity:** O(n) average, O(n²) worst
> **Space Complexity:** O(1) - in-place algorithm with no extra space

<br>
<br>

---

---

```code```
