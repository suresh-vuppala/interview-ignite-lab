Given a sorted array nums, remove the duplicates in-place such that each unique element appears only once. Return the new length k, with the first k elements being the unique values.

<br>

> Input:
> nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

> Output:
> 5, nums = [0, 1, 2, 3, 4, ...]

> Explanation:
> 5 unique values: 0,1,2,3,4. The first 5 positions hold these values. Remaining positions don't matter.
> 
> **Key insight:** Slow pointer marks the write position for the next unique element. Fast pointer scans ahead to find it.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 3 × 10⁴`
- `-100 ≤ nums[i] ≤ 100`
- `nums is sorted in non-decreasing order`

<br>

---

## All Possible Edge Cases

1. **All unique:** [1,2,3] → return 3, unchanged
2. **All same:** [1,1,1] → return 1
3. **Single element:** [5] → return 1
4. **Two elements same:** [1,1] → return 1
5. **Two elements different:** [1,2] → return 2

<br>

---

## Solution 1: Extra Array — Copy Unique Elements

**Intuition:**
Scan the sorted array, copy each new unique value into a separate array, then copy back.

**Algorithm:**
1. Create empty array `unique`
2. Add first element
3. For i = 1 to n-1: if nums[i] ≠ last added → add to unique
4. Copy unique back to nums
5. Return unique.size()

### Time Complexity: O(N)
**Why?**
- Single pass to find uniques: O(N)
- Copy back: O(K) where K = unique count

**Detailed breakdown:**
- Array size 30,000 → 30,000 comparisons + up to 30,000 copies

### Space Complexity: O(N)
**Why?**
- Extra array stores up to N unique elements

> **Drawback:**
> Uses O(N) extra space for the auxiliary array. Since the array is already sorted and duplicates are adjacent, we should be able to handle this in-place without any extra storage.

> **Key Insight for Improvement:**
> Use two pointers on the same array. Slow pointer `j` marks the last unique position. Fast pointer `i` scans forward. When nums[i] ≠ nums[j], advance j and write nums[i] there. O(1) space — the array overwrites itself.

<br>

---

## Solution 2: Slow/Fast Two Pointers (Optimal)

**Intuition:**
Pointer `j` = position of last unique element written. Pointer `i` scans the entire array. When `i` finds a new value (different from `j`), advance `j` and copy the new value.

**Algorithm:**
1. j = 0 (first element is always unique)
2. For i = 1 to n-1:
   - If nums[i] ≠ nums[j] → j++, nums[j] = nums[i]
3. Return j + 1

### Time Complexity: O(N)
**Why?**
- Single pass: N-1 comparisons
- At most N-1 writes

**Detailed breakdown:**
- Array size 30,000 → exactly 29,999 comparisons
- Writes: only when new unique found (at most K-1 writes)

**Example walkthrough:**
```
nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
       j=0

i=1: nums[1]=0 == nums[0]=0 → skip
i=2: nums[2]=1 ≠ nums[0]=0 → j=1, nums[1]=1 → [0,1,1,1,1,2,2,3,3,4]
i=3: nums[3]=1 == nums[1]=1 → skip
i=4: nums[4]=1 == nums[1]=1 → skip
i=5: nums[5]=2 ≠ nums[1]=1 → j=2, nums[2]=2 → [0,1,2,1,1,2,2,3,3,4]
i=6: skip (2==2)
i=7: nums[7]=3 ≠ nums[2]=2 → j=3, nums[3]=3
i=8: skip (3==3)
i=9: nums[9]=4 ≠ nums[3]=3 → j=4, nums[4]=4

Result: [0,1,2,3,4,...], return j+1 = 5 ✓
```

### Space Complexity: O(1)
**Why?**
- Only two pointer variables (i, j)
- All modifications done in-place

**Why this is optimal:**
- Must read every element: O(N) minimum
- O(1) space — purely in-place

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extra Array | O(N) | O(N) | Copy uniques to separate array |
| Slow/Fast Pointers | O(N) | O(1) | In-place overwrite with two pointers |

**Recommended Solution:** Slow/Fast Two Pointers (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Sorted property:** Duplicates are adjacent → only compare with last unique
2. **Slow/Fast pattern:** Slow writes, fast scans — classic in-place dedup
3. **Generalization:** Same pattern works for "remove duplicates allowing K occurrences"


<br>
<br>

---

```code```
