Merge nums2 into nums1 as one sorted array. nums1 has enough space (size m+n) to hold additional elements from nums2.

<br>

> Input:
> nums1 = [1, 2, 3, 0, 0, 0], m = 3
> nums2 = [2, 5, 6], n = 3

> Output:
> [1, 2, 2, 3, 5, 6]

> Explanation:
> Fill from the END using three pointers (avoids overwriting):
> - p1=2(3), p2=2(6), write=5: 6 > 3 → nums1[5]=6, p2--
> - p1=2(3), p2=1(5), write=4: 5 > 3 → nums1[4]=5, p2--
> - p1=2(3), p2=0(2), write=3: 3 > 2 → nums1[3]=3, p1--
> - p1=1(2), p2=0(2), write=2: 2 == 2 → nums1[2]=2, p1--
> - p1=0(1), p2=0(2), write=1: 2 > 1 → nums1[1]=2, p2--
> - p2 < 0, done. Remaining nums1 elements already in place.
> 
> **Key insight:** Fill from end to avoid overwriting unprocessed elements.

<br>

---

## Constraints

- `nums1.length == m + n`
- `nums2.length == n`
- `0 ≤ m, n ≤ 200`
- `1 ≤ m + n ≤ 200`
- `-10⁹ ≤ nums1[i], nums2[j] ≤ 10⁹`
- `nums1 has enough space (size m+n) to hold result`

<br>

---

## All Possible Edge Cases

1. **nums2 is empty (n=0):** nums1 already contains the result
2. **nums1 has no initial elements (m=0):** Copy all of nums2 into nums1
3. **All nums2 elements are larger:** nums2 appended to end of nums1
4. **All nums2 elements are smaller:** All nums1 elements shift right
5. **Interleaved values:** [1,3,5,0,0,0] and [2,4,6]
6. **Single element each:** [1,0] and [2]
7. **Duplicate values across arrays:** [1,2,3,0,0] and [2,3]

<br>

---

## Solution: Three Pointers from End

**Intuition:**
If we merge from the beginning, we'd overwrite nums1 elements. Instead, fill from the end — the back of nums1 is empty space. Compare the largest remaining elements and place at the write position.

**Algorithm:**
1. p1 = m - 1 (last real element in nums1)
2. p2 = n - 1 (last element in nums2)
3. write = m + n - 1 (last position in nums1)
4. While p1 >= 0 AND p2 >= 0:
   - If nums1[p1] > nums2[p2]: nums1[write] = nums1[p1], p1--
   - Else: nums1[write] = nums2[p2], p2--
   - write--
5. Copy remaining nums2 elements (if any): while p2 >= 0, nums1[write--] = nums2[p2--]

**Why no need to copy remaining nums1?**
- If p1 >= 0 but p2 < 0, those nums1 elements are already in correct position.

<br>

### Time Complexity: O(m + n) — each element processed once
### Space Complexity: O(1) — in-place merge

<br>
<br>

---

```code```
