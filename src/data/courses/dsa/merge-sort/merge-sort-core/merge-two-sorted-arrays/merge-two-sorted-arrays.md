Merge two sorted arrays into a single sorted array.

<br>

> Input:
> arr1 = [1, 3, 5, 7], arr2 = [2, 4, 6, 8]

> Output:
> [1, 2, 3, 4, 5, 6, 7, 8]

> Explanation:
> Compare elements from both arrays using two pointers
> Always pick the smaller element to maintain sorted order
> 
> **Key insight:** Two-pointer technique enables O(N+M) linear merge - fundamental building block of merge sort.

<br>

---

## Solution 1: Two Pointers with Extra Space

**Intuition:**
Both arrays are already sorted.
Use two pointers to compare elements from both arrays.
Always pick the smaller element and advance that pointer.
This maintains sorted order in the result.

**Algorithm:**
1. Create result array of size N + M
2. Initialize two pointers: i = 0 (arr1), j = 0 (arr2)
3. While both pointers are valid:
   - Compare arr1[i] and arr2[j]
   - Add smaller element to result
   - Advance the pointer of the array we took from
4. Copy remaining elements from non-empty array
5. Return result

**Example:**
```cpp
arr1 = [1, 3, 5], arr2 = [2, 4, 6]

Step-by-step:
i=0, j=0: arr1[0]=1 < arr2[0]=2 → result=[1], i=1
i=1, j=0: arr1[1]=3 > arr2[0]=2 → result=[1,2], j=1
i=1, j=1: arr1[1]=3 < arr2[1]=4 → result=[1,2,3], i=2
i=2, j=1: arr1[2]=5 > arr2[1]=4 → result=[1,2,3,4], j=2
i=2, j=2: arr1[2]=5 < arr2[2]=6 → result=[1,2,3,4,5], i=3
i=3 (out): Copy arr2[2:] → result=[1,2,3,4,5,6]
```

### Time Complexity: O(N + M)
**Why?**
- N = length of arr1
- M = length of arr2
- Each element from both arrays is visited exactly once
- Each comparison advances at least one pointer
- Total operations: N + M comparisons and copies

**Detailed breakdown:**
- Main loop: At most N + M iterations (each iteration advances a pointer)
- Each iteration: O(1) comparison and array assignment
- Copying remaining elements: O(remaining) ≤ O(max(N, M))
- Total: O(N + M)

### Space Complexity: O(N + M)
**Why?**
- Result array stores all elements: O(N + M)
- Two pointer variables: O(1)
- Total: O(N + M)

**Detailed breakdown:**
- Result array: N + M elements
- Variables (i, j, k): O(1)
- No recursion or additional data structures
- Total space: O(N + M)

> **Key Insight for Improvement:**
> If one array has extra space at the end, we can merge in-place by filling from the back! This saves O(N+M) space.

<br>

---

## Solution 2: In-Place Merge (Optimal for Space)

**Intuition:**
LeetCode problem: arr1 has size N+M, first N elements are valid, last M positions are empty.
Merge arr2 into arr1 without extra space.
Key trick: Fill from the END to avoid overwriting unprocessed elements.

**Algorithm:**
1. Initialize three pointers:
   - i = N - 1 (last valid element in arr1)
   - j = M - 1 (last element in arr2)
   - k = N + M - 1 (last position in arr1)
2. While j >= 0 (arr2 has elements):
   - If i >= 0 and arr1[i] > arr2[j]:
     - Place arr1[i] at position k
     - Decrement i and k
   - Else:
     - Place arr2[j] at position k
     - Decrement j and k
3. No need to copy remaining arr1 elements (already in place)

**Example:**
```cpp
arr1 = [1, 3, 5, 0, 0, 0], N=3
arr2 = [2, 4, 6], M=3

Fill from back:
i=2, j=2, k=5: arr1[2]=5 < arr2[2]=6 → arr1[5]=6, j=1, k=4
i=2, j=1, k=4: arr1[2]=5 > arr2[1]=4 → arr1[4]=5, i=1, k=3
i=1, j=1, k=3: arr1[1]=3 < arr2[1]=4 → arr1[3]=4, j=0, k=2
i=1, j=0, k=2: arr1[1]=3 > arr2[0]=2 → arr1[2]=3, i=0, k=1
i=0, j=0, k=1: arr1[0]=1 < arr2[0]=2 → arr1[1]=2, j=-1, k=0
j=-1: Done! arr1 = [1, 2, 3, 4, 5, 6]
```

**Why fill from back?**
- Filling from front would overwrite unprocessed arr1 elements
- Filling from back uses the empty space first
- Larger elements naturally go to the end

### Time Complexity: O(N + M)
**Why?**
- Each element from both arrays is processed exactly once
- Each iteration places one element and advances pointers
- Total operations: N + M

**Detailed breakdown:**
- Main loop: At most N + M iterations
- Each iteration: O(1) comparison and assignment
- No additional copying needed
- Total: O(N + M)

### Space Complexity: O(1)
**Why?**
- Merge happens in-place in arr1
- Only three pointer variables: O(1)
- No extra arrays or data structures
- Total: O(1) auxiliary space

**Detailed breakdown:**
- Variables (i, j, k): O(1)
- No additional arrays
- Modifying arr1 in-place
- Total auxiliary space: O(1)

**Improvement:** From O(N + M) space to O(1) space
- Example: N=1000, M=1000
- Extra space: 2000 integers ≈ 8KB saved
- Same time complexity, much better space efficiency!

**Why this is optimal:**
- Must examine all N + M elements: Ω(N + M) time lower bound
- Our solution does exactly this: O(N + M) time
- Cannot do better than O(N + M) time
- O(1) space is optimal for in-place variant

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Technique |
|----------|------|-------|---------------|
| Two Pointers + Extra Space | O(N + M) | O(N + M) | Compare and merge forward |
| In-Place Merge | O(N + M) | O(1) | Fill from back to avoid overwrites |

**Key Insights:**
1. **Sorted Property:** Both arrays sorted → two pointers can merge linearly
2. **Forward vs Backward:** Forward needs extra space, backward enables in-place
3. **Merge Sort Foundation:** This is the "merge" step in merge sort algorithm

**When to use each:**
- **Extra Space:** When you need to preserve both original arrays
- **In-Place:** When arr1 has extra capacity and space is critical (LeetCode 88)

> **Final Complexity:** O(N + M) time, O(1) space (in-place variant)

<br>

---

## Applications

1. **Merge Sort:** Core subroutine for merging sorted subarrays
2. **External Sorting:** Merge sorted chunks from disk
3. **Database Operations:** Merge sorted result sets from multiple sources
4. **K-Way Merge:** Foundation for merging K sorted arrays/lists
5. **Streaming Data:** Merge sorted streams in real-time systems

<br>
<br>

---

```code```