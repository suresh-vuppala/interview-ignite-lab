Sort an array using the Insertion Sort algorithm. Build a sorted portion one element at a time by inserting each element into its correct position.

<br>

> Input:
> nums = [5, 2, 4, 6, 1, 3]

> Output:
> [1, 2, 3, 4, 5, 6]

> Explanation:
> [5] | 2 4 6 1 3 — insert 2 → [2, 5]
> [2, 5] | 4 6 1 3 — insert 4 → [2, 4, 5]
> [2, 4, 5] | 6 1 3 — insert 6 → [2, 4, 5, 6]
> [2, 4, 5, 6] | 1 3 — insert 1 → [1, 2, 4, 5, 6]
> [1, 2, 4, 5, 6] | 3 — insert 3 → [1, 2, 3, 4, 5, 6]
> 
> **Key insight:** Like sorting cards — pick next card, shift larger cards right, insert in correct spot.

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 10⁴`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Already sorted:** O(n) — each element compared once
2. **Reverse sorted:** O(n²) — maximum shifts
3. **Single element:** Already sorted
4. **Empty array:** Nothing to sort
5. **All same elements:** No shifts needed
6. **Nearly sorted (few inversions):** Very efficient — O(n + d) where d = inversions
7. **Duplicates:** Stable sort preserves order

<br>

---

## Solution: Insertion Sort

**Algorithm:**
1. For i = 1 to n-1:
   - key = arr[i]
   - j = i - 1
   - While j >= 0 AND arr[j] > key:
     - arr[j+1] = arr[j] (shift right)
     - j--
   - arr[j+1] = key (insert)

**Properties:**
- **Stable:** Yes
- **In-place:** Yes (O(1) space)
- **Adaptive:** Yes (O(n) for nearly sorted — best among simple sorts)
- **Online:** Yes (can sort as data arrives)

**When to use:** Small arrays (< 50 elements), nearly sorted data, or as inner sort in hybrid algorithms (Timsort uses insertion sort for small runs).

<br>

### Time Complexity
- **Best:** O(n) — already sorted
- **Average:** O(n²)
- **Worst:** O(n²) — reverse sorted

### Space Complexity: O(1) — in-place

<br>
<br>

---

```code```
