Implement Quick Sort algorithm to sort an array in ascending order.

<br>

> Input:
> arr = [10, 7, 8, 9, 1, 5]

> Output:
> [1, 5, 7, 8, 9, 10]

> Explanation:
> Using pivot = 5 (last element):
> - Partition: [1] + [5] + [10, 7, 8, 9]
> - Recursively sort left [1] → [1]
> - Recursively sort right [10, 7, 8, 9] → [7, 8, 9, 10]
> - Final result: [1, 5, 7, 8, 9, 10]

<br>

---

## Solution: Quick Sort

Quick Sort uses divide-and-conquer strategy:
1. Choose a pivot element (typically last element)
2. Partition array: elements < pivot on left, > pivot on right
3. Recursively sort left and right subarrays

```code```

<br>

### Time Complexity Analysis

**Average Case: O(n log n)**
- At each level, we partition the array in O(n) time
- With balanced partitions, we get log n levels (dividing array in half each time)
- Total: n × log n = O(n log n)

**Worst Case: O(n²)**
- Occurs when pivot is always smallest/largest element (already sorted array)
- Creates unbalanced partitions: n-1 elements on one side, 0 on other
- Recursion depth becomes n, each level does O(n) work
- Total: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = O(n²)

**Best Case: O(n log n)**
- Occurs when pivot always divides array into equal halves
- Same as average case

> **Time Complexity:** O(n log n) average, O(n²) worst
> **Space Complexity:** O(log n) for recursion stack in average case, O(n) in worst case

<br>
<br>

---