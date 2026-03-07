Implement Quick Sort algorithm to sort an array in ascending order using divide-and-conquer strategy.

<br>

> Input:
> arr = [10, 7, 8, 9, 1, 5]

> Output:
> [1, 5, 7, 8, 9, 10]

> Explanation:
> Quick Sort picks a pivot and partitions array around it
> Elements smaller than pivot go left, larger go right
> 
> **Key insight:** Divide-and-conquer with in-place partitioning for O(N log N) average time.

<br>

---

## Solution: Quick Sort with Lomuto Partition

**Intuition:**
Pick a pivot element (usually last element).
Rearrange array so all elements smaller than pivot are on left, larger on right.
Recursively sort left and right subarrays.
Pivot ends up in its final sorted position after partition.

**Partition Algorithm (Lomuto):**
```cpp
Choose pivot = arr[high]
i = low - 1  // Index of smaller element

For j from low to high-1:
    If arr[j] < pivot:
        i++
        swap(arr[i], arr[j])

swap(arr[i+1], arr[high])  // Place pivot in correct position
return i+1  // Pivot index
```

**Algorithm:**
1. If low < high:
   - Partition array around pivot
   - Recursively sort left subarray (low to pivot-1)
   - Recursively sort right subarray (pivot+1 to high)
2. Base case: single element or empty (already sorted)

**Example Walkthrough:**
```
arr = [10, 7, 8, 9, 1, 5]

quickSort(0, 5):
  Partition with pivot=5:
    i=-1, j=0: arr[0]=10 > 5, skip
    i=-1, j=1: arr[1]=7 > 5, skip
    i=-1, j=2: arr[2]=8 > 5, skip
    i=-1, j=3: arr[3]=9 > 5, skip
    i=-1, j=4: arr[4]=1 < 5, i=0, swap(arr[0], arr[4])
      arr = [1, 7, 8, 9, 10, 5]
    swap(arr[1], arr[5]) → arr = [1, 5, 8, 9, 10, 7]
    pivot index = 1
  
  quickSort(0, 0): [1] already sorted
  quickSort(2, 5): [8, 9, 10, 7]
    Partition with pivot=7:
      i=1, j=2: arr[2]=8 > 7, skip
      i=1, j=3: arr[3]=9 > 7, skip
      i=1, j=4: arr[4]=10 > 7, skip
      swap(arr[2], arr[5]) → arr = [1, 5, 7, 9, 10, 8]
      pivot index = 2
    
    quickSort(2, 1): empty
    quickSort(3, 5): [9, 10, 8]
      Partition with pivot=8:
        i=2, j=3: arr[3]=9 > 8, skip
        i=2, j=4: arr[4]=10 > 8, skip
        swap(arr[3], arr[5]) → arr = [1, 5, 7, 8, 10, 9]
        pivot index = 3
      
      quickSort(3, 2): empty
      quickSort(4, 5): [10, 9]
        Partition with pivot=9:
          i=3, j=4: arr[4]=10 > 9, skip
          swap(arr[4], arr[5]) → arr = [1, 5, 7, 8, 9, 10]
          pivot index = 4
        
        quickSort(4, 3): empty
        quickSort(5, 5): [10] already sorted

Final: [1, 5, 7, 8, 9, 10]
```

**Recursion Tree:**
```
                [10,7,8,9,1,5]
                      |
                  pivot=5
                /           \
              [1]         [8,9,10,7]
                              |
                          pivot=7
                          /       \
                        []      [9,10,8]
                                   |
                               pivot=8
                               /      \
                             []     [10,9]
                                      |
                                  pivot=9
                                  /     \
                                []     [10]
```

### Time Complexity: O(N log N) average, O(N²) worst
**Why?**
- **Average case:** Pivot divides array roughly in half
  - Recursion depth: O(log N)
  - Each level: O(N) for partitioning
  - Total: O(N log N)
- **Worst case:** Pivot is always smallest/largest (sorted array)
  - Recursion depth: O(N)
  - Each level: O(N) for partitioning
  - Total: O(N²)

**Detailed breakdown:**
- Partition operation: O(N) - single pass through array
- Best/Average: log N levels × N work per level = O(N log N)
- Worst: N levels × N work per level = O(N²)

### Space Complexity: O(log N) average, O(N) worst
**Why?**
- Recursion stack space
- Average case: O(log N) depth with balanced partitions
- Worst case: O(N) depth with unbalanced partitions
- In-place sorting: no extra array space needed

<br>

---

## Optimization: Randomized Quick Sort

**Problem with Basic Quick Sort:**
Worst case O(N²) occurs on already sorted arrays (common in practice).

**Solution:**
Choose random pivot instead of always picking last element.

**Randomized Partition:**
```cpp
int randomizedPartition(arr, low, high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);  // Move random pivot to end
    return partition(arr, low, high);   // Standard partition
}
```

**Time:** O(N log N) expected (worst case still O(N²) but extremely unlikely)
**Space:** O(log N) expected

<br>

---

## Alternative: Hoare Partition Scheme

**Difference from Lomuto:**
- Uses two pointers moving from both ends
- Generally more efficient (fewer swaps)
- Pivot doesn't end up in final position after partition

**Hoare Partition:**
```cpp
int hoarePartition(arr, low, high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}
```

**Advantages:**
- 3× fewer swaps on average than Lomuto
- Better performance in practice

<br>

---

## Key Insights

1. **Divide-and-Conquer:** Break problem into smaller subproblems
2. **In-Place:** No extra array needed (unlike Merge Sort)
3. **Unstable:** Relative order of equal elements not preserved
4. **Pivot Choice Matters:** Random pivot avoids worst case
5. **Cache-Friendly:** Good locality of reference

**Common Mistakes:**
- Not handling base case (low >= high)
- Wrong partition logic (off-by-one errors)
- Not swapping pivot to correct position
- Forgetting to return pivot index from partition

<br>

---

## Comparison with Other Sorts

| Algorithm | Time (Avg) | Time (Worst) | Space | Stable | In-Place |
|-----------|------------|--------------|-------|--------|----------|
| Quick Sort | O(N log N) | O(N²) | O(log N) | No | Yes |
| Merge Sort | O(N log N) | O(N log N) | O(N) | Yes | No |
| Heap Sort | O(N log N) | O(N log N) | O(1) | No | Yes |
| Bubble Sort | O(N²) | O(N²) | O(1) | Yes | Yes |

**When to use Quick Sort:**
- Average case performance matters most
- Memory is limited (in-place)
- Stability not required
- Random/unsorted data

**When NOT to use Quick Sort:**
- Guaranteed O(N log N) required (use Merge/Heap Sort)
- Stability required (use Merge Sort)
- Already sorted data without randomization

<br>

---

## Optimizations

**1. Tail Call Elimination:**
Recurse on smaller partition first to limit stack depth to O(log N).

**2. Insertion Sort for Small Subarrays:**
Switch to Insertion Sort when subarray size < 10-15 elements.

**3. Three-Way Partitioning:**
Handle duplicate elements efficiently (Dutch National Flag).

**4. Median-of-Three Pivot:**
Choose median of first, middle, last elements as pivot.

<br>

---

## Applications

1. **Standard Library:** Used in many language sort implementations (with optimizations)
2. **Database Systems:** Query result sorting
3. **Selection Algorithms:** Finding Kth smallest/largest element
4. **Partitioning Problems:** Separate elements by condition
5. **Randomized Algorithms:** Foundation for randomized selection

<br>
<br>

---

```code```
