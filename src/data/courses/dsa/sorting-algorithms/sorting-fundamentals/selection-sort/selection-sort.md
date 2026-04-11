Sort an array using the Selection Sort algorithm. Repeatedly find the minimum element from the unsorted portion and place it at the beginning.

<br>

> Input:
> nums = [29, 10, 14, 37, 13]

> Output:
> [10, 13, 14, 29, 37]

> Explanation:
> Pass 1: Find min(29,10,14,37,13)=10, swap with pos 0 → [10, 29, 14, 37, 13]
> Pass 2: Find min(29,14,37,13)=13, swap with pos 1 → [10, 13, 14, 37, 29]
> Pass 3: Find min(14,37,29)=14, already at pos 2 → [10, 13, 14, 37, 29]
> Pass 4: Find min(37,29)=29, swap with pos 3 → [10, 13, 14, 29, 37]
> 
> **Key insight:** In each pass, select the smallest remaining element. Minimum number of swaps (at most n-1), but always O(n²) comparisons.

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 10⁴`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Already sorted:** Still O(n²) — always scans for minimum
2. **Reverse sorted:** O(n²) — same number of comparisons
3. **Single element:** Already sorted
4. **Empty array:** Nothing to sort
5. **All same elements:** No swaps needed but still O(n²) comparisons
6. **Duplicates:** Not stable (can change relative order of equal elements)

<br>

---

## Solution: Selection Sort

**Algorithm:**
1. For i = 0 to n-2:
   - minIdx = i
   - For j = i+1 to n-1:
     - If arr[j] < arr[minIdx]: minIdx = j
   - Swap arr[i] and arr[minIdx]

**Properties:**
- **Stable:** No (swapping can change relative order of equal elements)
- **In-place:** Yes (O(1) space)
- **Adaptive:** No (always O(n²) regardless of input order)
- **Minimum swaps:** Yes (at most n-1 swaps — useful when writes are expensive)

<br>

### Time Complexity
- **Best:** O(n²) — always scans entire unsorted portion
- **Average:** O(n²)
- **Worst:** O(n²)

### Space Complexity: O(1) — in-place

<br>
<br>

---

```code```
