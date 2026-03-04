Find the kth largest element in an unsorted array using QuickSelect algorithm.

<br>

> Input:
> arr = [3, 2, 1, 5, 6, 4], k = 2

> Output:
> 5

> Explanation:
> Sorted array would be [1, 2, 3, 4, 5, 6]
> The 2nd largest element is 5 (at position n-k = 6-2 = 4 in 0-indexed array)
> 
> QuickSelect process:
> - We need element at index n-k = 4
> - Partition around pivot 4: [3, 2, 1] + [4] + [5, 6]
> - Pivot at index 3, target=4, so search right subarray
> - Partition [5, 6] around pivot 6: [5] + [6]
> - Pivot at index 4, matches target, return 5

<br>

---

## Solution: QuickSelect for Kth Largest

Modified QuickSelect to find kth largest:
1. Convert problem: kth largest = (n-k)th smallest
2. Partition array around pivot
3. If pivot index == n-k, return pivot
4. Recurse on left or right based on position

```code```

<br>

### Time Complexity Analysis

**Average Case: O(n)**
- First partition: n comparisons
- Second partition: n/2 comparisons (on average)
- Third partition: n/4 comparisons
- Total: n + n/2 + n/4 + ... = 2n = O(n)
- We only recurse on one partition, not both sides

**Worst Case: O(n²)**
- Occurs when pivot selection is poor (always min/max)
- Must process n + (n-1) + (n-2) + ... = O(n²) elements
- Randomized pivot selection makes this extremely unlikely

**Best Case: O(n)**
- Occurs when pivot consistently divides array well
- Same as average case

**Why faster than sorting?**
- Sorting: O(n log n) - must process all elements at all levels
- QuickSelect: O(n) - only processes one partition at each level

> **Time Complexity:** O(n) average, O(n²) worst
> **Space Complexity:** O(1) - in-place with no extra space needed

<br>
<br>

---