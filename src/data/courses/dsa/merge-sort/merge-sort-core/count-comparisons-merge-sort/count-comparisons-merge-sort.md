Count the total number of comparisons made during merge sort execution.

<br>

> Input:
> arr = [38, 27, 43, 3, 9, 82, 10]

> Output:
> Sorted: [3, 9, 10, 27, 38, 43, 82]
> Comparisons: 13

> Explanation:
> Track comparisons during merge phase
> Each comparison decides which element to pick
> 
> **Key insight:** Comparisons happen only during merge, not during divide phase.

<br>

---

## Understanding Comparisons in Merge Sort

**Where Comparisons Happen:**
- **Divide Phase:** No comparisons (just finding middle)
- **Merge Phase:** All comparisons happen here

**What Counts as Comparison:**
```cpp
if (left[i] <= right[j]) {  // ← This is a comparison
    result.append(left[i])
    i++
} else {
    result.append(right[j])
    j++
}
```

<br>

---

## Solution: Modified Merge Sort with Counter

**Intuition:**
Add a counter variable.
Increment counter each time we compare two elements during merge.
Return both sorted array and comparison count.

**Algorithm:**
1. **Divide:** Split array into two halves (no comparisons)
2. **Recursively sort:** Count comparisons in left and right halves
3. **Merge:** Count comparisons while merging
   - Each time we compare left[i] and right[j], increment counter
4. **Return:** Total count = left_count + right_count + merge_count

**Example Walkthrough:**
```
arr = [38, 27, 43, 3, 9, 82, 10]

Level 1: Split [38, 27, 43, 3] and [9, 82, 10]

Left [38, 27, 43, 3]:
  Level 2: Split [38, 27] and [43, 3]
  
  Left [38, 27]:
    Level 3: Split [38] and [27]
    Merge: Compare 38 vs 27 → 1 comparison
    Result: [27, 38], count = 1
  
  Right [43, 3]:
    Level 3: Split [43] and [3]
    Merge: Compare 43 vs 3 → 1 comparison
    Result: [3, 43], count = 1
  
  Merge [27, 38] and [3, 43]:
    Compare 27 vs 3 → 1 comparison (pick 3)
    Compare 27 vs 43 → 1 comparison (pick 27)
    Compare 38 vs 43 → 1 comparison (pick 38)
    Remaining: 43
    Result: [3, 27, 38, 43], count = 3
  
  Left subtree total: 1 + 1 + 3 = 5 comparisons

Right [9, 82, 10]:
  Level 2: Split [9, 82] and [10]
  
  Left [9, 82]:
    Level 3: Split [9] and [82]
    Merge: Compare 9 vs 82 → 1 comparison
    Result: [9, 82], count = 1
  
  Right [10]: Single element, count = 0
  
  Merge [9, 82] and [10]:
    Compare 9 vs 10 → 1 comparison (pick 9)
    Compare 82 vs 10 → 1 comparison (pick 10)
    Remaining: 82
    Result: [9, 10, 82], count = 2
  
  Right subtree total: 1 + 0 + 2 = 3 comparisons

Final Merge [3, 27, 38, 43] and [9, 10, 82]:
  Compare 3 vs 9 → 1 comparison (pick 3)
  Compare 27 vs 9 → 1 comparison (pick 9)
  Compare 27 vs 10 → 1 comparison (pick 10)
  Compare 27 vs 82 → 1 comparison (pick 27)
  Compare 38 vs 82 → 1 comparison (pick 38)
  Remaining: 43, 82
  Result: [3, 9, 10, 27, 38, 43, 82], count = 5

Total Comparisons: 5 + 3 + 5 = 13
```

**Detailed Merge Phase:**
```
Merge [27, 38] and [3, 43]:
  i=0, j=0: 27 vs 3 → 3 < 27 → pick 3, j++ → count = 1
  i=0, j=1: 27 vs 43 → 27 < 43 → pick 27, i++ → count = 2
  i=1, j=1: 38 vs 43 → 38 < 43 → pick 38, i++ → count = 3
  i=2: left exhausted, append [43]
  Total: 3 comparisons

Merge [9, 82] and [10]:
  i=0, j=0: 9 vs 10 → 9 < 10 → pick 9, i++ → count = 1
  i=1, j=0: 82 vs 10 → 10 < 82 → pick 10, j++ → count = 2
  j=1: right exhausted, append [82]
  Total: 2 comparisons

Merge [3, 27, 38, 43] and [9, 10, 82]:
  i=0, j=0: 3 vs 9 → 3 < 9 → pick 3, i++ → count = 1
  i=1, j=0: 27 vs 9 → 9 < 27 → pick 9, j++ → count = 2
  i=1, j=1: 27 vs 10 → 10 < 27 → pick 10, j++ → count = 3
  i=1, j=2: 27 vs 82 → 27 < 82 → pick 27, i++ → count = 4
  i=2, j=2: 38 vs 82 → 38 < 82 → pick 38, i++ → count = 5
  i=3: append [43, 82]
  Total: 5 comparisons
```

### Time Complexity: O(N log N)
**Why?**
- Same as regular merge sort
- Counting adds O(1) per comparison
- Total: O(N log N)

**Detailed breakdown:**
- Divide: O(log N) levels
- Merge at each level: O(N) work + O(N) comparisons
- Total: O(N log N)

### Space Complexity: O(N)
**Why?**
- Temporary arrays: O(N)
- Recursion stack: O(log N)
- Counter variable: O(1)
- Total: O(N)

<br>

---

## Comparison Count Analysis

**Best Case:**
When array is already sorted or reverse sorted.
```
arr = [1, 2, 3, 4]

Merge [1, 2] and [3, 4]:
  1 < 3 → pick 1
  2 < 3 → pick 2
  Append [3, 4]
  Comparisons: 2 (minimum for merging 4 elements)
```

**Worst Case:**
When elements alternate between subarrays.
```
arr = [1, 3, 2, 4]

After sorting halves: [1, 3] and [2, 4]
Merge:
  1 < 2 → pick 1
  3 > 2 → pick 2
  3 < 4 → pick 3
  Append [4]
  Comparisons: 3 (maximum for merging 4 elements)
```

**Formula:**
- Minimum comparisons: N - 1
- Maximum comparisons: N × log N
- Average comparisons: ~N × log N

<br>

---

## Why Count Comparisons?

**1. Algorithm Analysis:**
- Measure actual work done
- Compare different sorting algorithms
- Understand performance characteristics

**2. Comparison-Based Lower Bound:**
- Any comparison-based sort needs Ω(N log N) comparisons
- Merge sort is optimal in this sense

**3. Practical Performance:**
- Comparisons can be expensive (custom objects)
- Counting helps optimize for specific data types

**4. Teaching Tool:**
- Visualize algorithm execution
- Understand merge sort behavior
- Debug implementation

<br>

---

## Comparison with Other Sorts

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Merge Sort | N log N | N log N | N log N |
| Quick Sort | N log N | N log N | N² |
| Heap Sort | N log N | N log N | N log N |
| Insertion Sort | N | N² | N² |
| Bubble Sort | N | N² | N² |

**Merge Sort Characteristics:**
- Consistent comparison count
- Always O(N log N) comparisons
- Predictable performance

<br>

---

## Implementation Variations

**1. Global Counter:**
```cpp
int count = 0;

void merge(arr, left, mid, right) {
    while (i < n1 && j < n2) {
        count++;  // Increment global counter
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
}
```

**2. Return Value:**
```cpp
int mergeSort(arr) {
    if (len(arr) <= 1) return 0;
    
    left_count = mergeSort(left_half);
    right_count = mergeSort(right_half);
    merge_count = merge(left_half, right_half);
    
    return left_count + right_count + merge_count;
}
```

**3. Pass by Reference:**
```cpp
void mergeSort(arr, &count) {
    if (len(arr) <= 1) return;
    
    mergeSort(left_half, count);
    mergeSort(right_half, count);
    merge(left_half, right_half, count);
}
```

<br>

---

## Edge Cases

1. **Empty array:** 0 comparisons
2. **Single element:** 0 comparisons
3. **Two elements:** 1 comparison
4. **Already sorted:** Minimum comparisons
5. **Reverse sorted:** Still O(N log N) comparisons

<br>

---

## Applications

1. **Algorithm Benchmarking:** Compare sorting algorithm efficiency
2. **Performance Tuning:** Identify bottlenecks in sorting
3. **Educational Tools:** Visualize algorithm execution
4. **Complexity Verification:** Confirm O(N log N) behavior
5. **Custom Comparators:** Measure cost of expensive comparisons

<br>
<br>

---

```code```
