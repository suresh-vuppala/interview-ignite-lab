Implement the merge sort algorithm to sort an array in ascending order.

<br>

> Input:
> arr = [38, 27, 43, 3, 9, 82, 10]

> Output:
> [3, 9, 10, 27, 38, 43, 82]

> Explanation:
> Divide and conquer process:
> 
> **Divide Phase:**
> - [38, 27, 43, 3, 9, 82, 10]
> - Split: [38, 27, 43, 3] and [9, 82, 10]
> - Split: [38, 27], [43, 3], [9, 82], [10]
> - Split: [38], [27], [43], [3], [9], [82], [10]
> 
> **Merge Phase:**
> - Merge [38] and [27] → [27, 38]
> - Merge [43] and [3] → [3, 43]
> - Merge [27, 38] and [3, 43] → [3, 27, 38, 43]
> - Merge [9] and [82] → [9, 82]
> - Merge [9, 82] and [10] → [9, 10, 82]
> - Merge [3, 27, 38, 43] and [9, 10, 82] → [3, 9, 10, 27, 38, 43, 82]

<br>

---

## Solution: Merge Sort

Merge sort is a divide-and-conquer algorithm:
1. **Divide**: Split array into two halves recursively until single elements
2. **Conquer**: Recursively sort both halves
3. **Combine**: Merge the two sorted halves into one sorted array

```code```

<br>

### Time Complexity Analysis

**Divide Phase: O(log n)**
- Array is divided into halves recursively
- Depth of recursion tree = log₂ n
- Each level divides all elements

**Merge Phase: O(n) per level**
- At each level, we merge all n elements
- Merging two sorted arrays takes O(n) time
- Uses two pointers to compare and merge

**Overall: O(n log n)**
- log n levels in recursion tree
- Each level processes n elements
- Total: n × log n = O(n log n)

**All Cases: O(n log n)**
- Best case: O(n log n) - already sorted
- Average case: O(n log n) - random order
- Worst case: O(n log n) - reverse sorted
- Unlike QuickSort, merge sort is consistent across all cases

**Why O(n log n)?**
- Recurrence relation: T(n) = 2T(n/2) + O(n)
- Solving using Master Theorem: T(n) = O(n log n)

> **Time Complexity:** O(n log n) - all cases
> **Space Complexity:** O(n) - temporary arrays for merging + O(log n) recursion stack

<br>
<br>

---