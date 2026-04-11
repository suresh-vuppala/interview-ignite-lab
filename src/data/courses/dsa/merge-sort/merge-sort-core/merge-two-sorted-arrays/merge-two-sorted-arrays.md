You are given two integer arrays nums1 and nums2, sorted in non-decreasing order. Merge nums2 into nums1 as one sorted array. nums1 has extra space at the end to hold all elements.

<br>

> Input:
> nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3

> Output:
> [1, 2, 2, 3, 5, 6]

> Explanation:
> Merge [1,2,3] and [2,5,6] into nums1 which has room for 6 elements.
> 
> **Key insight:** Fill from the END of nums1. Compare the largest elements from both arrays, place the larger at the back. This avoids overwriting elements we haven't processed yet.

<br>



---

## Constraints

- `nums1.length == m + n`
- `nums2.length == n`
- `0 ≤ m, n ≤ 200`

<br>

---

## All Possible Edge Cases

1. **nums2 is empty (n=0):** nums1 already complete
2. **nums1 is empty (m=0):** Copy nums2 into nums1
3. **nums2 all smaller:** [3,4,5,0,0] + [1,2]
4. **nums2 all larger:** [1,2,0,0] + [3,4]

<br>

---

## Solution 1: Copy + Sort

**Intuition:**
Copy nums2 into the back of nums1, then sort the entire array.

### Time Complexity: O((M+N) log(M+N))
**Why?**
- Copy: O(N)
- Sort: O((M+N) log(M+N)) — dominates

**Detailed breakdown:**
- M=N=200 → sort ~400 elements: ~3,440 operations

### Space Complexity: O(1) or O(M+N)
**Why?**
- Depends on sort algorithm

> **Drawback:**
> Sorting is O((M+N) log(M+N)) and ignores the fact that both arrays are ALREADY sorted. We're discarding useful information.

> **Key Insight for Improvement:**
> Since both arrays are sorted, we can merge them in O(M+N) time. Fill from the END to avoid overwriting: compare the largest remaining elements from both arrays, place the larger at position k (starting from m+n-1 and decreasing).

<br>

---

## Solution 2: Three Pointers from End (Optimal)

**Intuition:**
Start from the end of both arrays and the end of nums1's capacity. Compare the largest elements, place the bigger one at the back.

**Algorithm:**
1. i = m-1 (last real element in nums1)
2. j = n-1 (last element in nums2)
3. k = m+n-1 (last position in nums1)
4. While j ≥ 0:
   - If i ≥ 0 and nums1[i] > nums2[j] → nums1[k--] = nums1[i--]
   - Else → nums1[k--] = nums2[j--]

### Time Complexity: O(M + N)
**Why?**
- Each element placed exactly once
- Total: M + N placements

**Detailed breakdown:**
- M=N=200 → 400 operations
- Compared to sort: 3,440 → 400 (8.6× faster!)

**Example walkthrough:**
```
nums1 = [1,2,3,0,0,0], nums2 = [2,5,6]
i=2, j=2, k=5

nums1[2]=3 vs nums2[2]=6 → 6 wins → nums1[5]=6, j=1, k=4
nums1[2]=3 vs nums2[1]=5 → 5 wins → nums1[4]=5, j=0, k=3
nums1[2]=3 vs nums2[0]=2 → 3 wins → nums1[3]=3, i=1, k=2
nums1[1]=2 vs nums2[0]=2 → 2(nums2) → nums1[2]=2, j=-1, k=1

j < 0 → stop (remaining nums1 elements already in place)
Result: [1, 2, 2, 3, 5, 6] ✓
```

**Why fill from the end?**
- Filling from the start would overwrite nums1 elements we haven't processed
- From the end: the "empty" space in nums1 is at the back — safe to write there

### Space Complexity: O(1)
**Why?**
- Only three pointer variables — purely in-place

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Copy + Sort | O((M+N)log(M+N)) | O(1) | Ignore sorted property |
| Three Pointers End | O(M+N) | O(1) | Merge from back — no overwrite |

**Recommended Solution:** Three Pointers from End (Solution 2) — O(M+N) time, O(1) space.

**Key Insights:**
1. **Fill from back:** Avoids overwriting unprocessed elements
2. **Only need to drain nums2:** If nums2 is exhausted, remaining nums1 elements are already in place
3. **Classic merge pattern:** Foundation for merge sort


<br>
<br>

---

```code```
