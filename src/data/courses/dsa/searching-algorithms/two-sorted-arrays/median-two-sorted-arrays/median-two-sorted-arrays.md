## Problem Statement

Given two sorted arrays `nums1` and `nums2` of sizes `m` and `n` respectively, find the **median** of the two sorted arrays.

The overall run time complexity should be **O(log(min(m, n)))**.

## Examples

### Example 1
```
Input: nums1 = [1, 3], nums2 = [2]
Output: 2.0
Explanation: Merged array = [1, 2, 3], median = 2
```

### Example 2
```
Input: nums1 = [1, 2], nums2 = [3, 4]
Output: 2.5
Explanation: Merged array = [1, 2, 3, 4], median = (2 + 3) / 2 = 2.5
```

### Example 3
```
Input: nums1 = [1, 3, 8, 9, 15], nums2 = [7, 11, 18, 19, 21, 25]
Output: 11.0
Explanation: Merged array has 11 elements, median is the 6th element = 11
```

## Visual Walkthrough

### Understanding Median

For a combined sorted array of size `n`:
- If `n` is **odd**: median = middle element
- If `n` is **even**: median = average of two middle elements

### Example: nums1 = [1, 3, 8, 9], nums2 = [7, 11, 18, 19, 21]

```
Total elements = 4 + 5 = 9 (odd)
Median position = 5th element (index 4)

We need to partition both arrays such that:
- Left partition has 4 elements
- Right partition has 5 elements
- max(left) ≤ min(right)
```

### Binary Search Approach Visualization

```
nums1 = [1, 3, 8, 9]        (m = 4)
nums2 = [7, 11, 18, 19, 21] (n = 5)

Total = 9, need 4 elements on left side

Step 1: Try partition at mid of nums1
nums1: [1, 3] | [8, 9]           (cut1 = 2)
nums2: [7, 11] | [18, 19, 21]    (cut2 = 2)

Left:  [1, 3, 7, 11]    max_left = 11
Right: [8, 9, 18, 19, 21]  min_right = 8

Check: 11 > 8 ❌ (invalid partition)
Move left in nums1

Step 2: Try smaller partition in nums1
nums1: [1] | [3, 8, 9]           (cut1 = 1)
nums2: [7, 11, 18] | [19, 21]    (cut2 = 3)

Left:  [1, 7, 11, 18]    max_left = 18
Right: [3, 8, 9, 19, 21]   min_right = 3

Check: 18 > 3 ❌ (invalid partition)
Move left in nums1

Step 3: Try partition at start of nums1
nums1: [] | [1, 3, 8, 9]         (cut1 = 0)
nums2: [7, 11, 18, 19] | [21]    (cut2 = 4)

Left:  [7, 11, 18, 19]    max_left = 19
Right: [1, 3, 8, 9, 21]     min_right = 1

Check: 19 > 1 ❌ (invalid partition)

Step 4: Binary search on nums2 instead (smaller array)
Actually, we should binary search on the smaller array!

Restart with nums1 as smaller:
nums1: [1, 3] | [8, 9]           (cut1 = 2)
nums2: [7, 11] | [18, 19, 21]    (cut2 = 2)

Left max:  max(3, 11) = 11
Right min: min(8, 18) = 8

Since 11 > 8, move right boundary

Final partition:
nums1: [1, 3, 8] | [9]           (cut1 = 3)
nums2: [7] | [11, 18, 19, 21]    (cut2 = 1)

Left:  [1, 3, 7, 8]      max_left = 8
Right: [9, 11, 18, 19, 21]  min_right = 9

Check: 8 ≤ 9 ✓ (valid partition)

Median = max_left = 8 (for odd total)
Wait, let me recalculate...

Actually for 9 elements, we need 5 on left:
nums1: [1, 3, 8, 9] | []         (cut1 = 4)
nums2: [7] | [11, 18, 19, 21]    (cut2 = 1)

Left:  [1, 3, 7, 8, 9]    max_left = 9
Right: [11, 18, 19, 21]     min_right = 11

Check: 9 ≤ 11 ✓
Median = 9? No...

Let me recalculate properly:
For 9 elements, median is at position 5 (0-indexed: 4)
Left partition should have 5 elements

nums1: [1, 3, 8, 9] | []         (cut1 = 4)
nums2: [7] | [11, 18, 19, 21]    (cut2 = 1)

Left has 5 elements: 1, 3, 7, 8, 9
Right has 4 elements: 11, 18, 19, 21

max_left = max(9, 7) = 9
min_right = min(∞, 11) = 11

Median = max_left = 9? 

Hmm, let me verify by merging:
[1, 3, 7, 8, 9, 11, 18, 19, 21]
Position 4 (5th element) = 9 ❌

Actually merged: [1, 3, 7, 8, 9, 11, 18, 19, 21]
Median (5th element) = 9 ✓

Wait, I need to recount:
[1, 3, 7, 8, 9, 11, 18, 19, 21]
 0  1  2  3  4   5   6   7   8

5th element (index 4) = 9 ✓
```

Let me redo this more carefully:

```
nums1 = [1, 3, 8, 9]        (m = 4)
nums2 = [7, 11, 18, 19, 21] (n = 5)

Merged: [1, 3, 7, 8, 9, 11, 18, 19, 21]
Total = 9 (odd), median = element at index 4 = 9

Binary search on nums1 (smaller array):
We need (9 + 1) / 2 = 5 elements on left

Try cut1 = 2 (elements [1, 3] on left from nums1)
Then cut2 = 5 - 2 = 3 (elements [7, 11, 18] on left from nums2)

nums1: [1, 3] | [8, 9]
nums2: [7, 11, 18] | [19, 21]

left1 = 3, right1 = 8
left2 = 18, right2 = 19

Check: left1 ≤ right2? 3 ≤ 19 ✓
Check: left2 ≤ right1? 18 ≤ 8 ❌

left2 > right1, so we need more elements from nums1
Move left boundary: low = cut1 + 1 = 3

Try cut1 = 3 (elements [1, 3, 8] on left from nums1)
Then cut2 = 5 - 3 = 2 (elements [7, 11] on left from nums2)

nums1: [1, 3, 8] | [9]
nums2: [7, 11] | [18, 19, 21]

left1 = 8, right1 = 9
left2 = 11, right2 = 18

Check: left1 ≤ right2? 8 ≤ 18 ✓
Check: left2 ≤ right1? 11 ≤ 9 ❌

left2 > right1, so we need more elements from nums1
Move left boundary: low = cut1 + 1 = 4

Try cut1 = 4 (all elements from nums1 on left)
Then cut2 = 5 - 4 = 1 (element [7] on left from nums2)

nums1: [1, 3, 8, 9] | []
nums2: [7] | [11, 18, 19, 21]

left1 = 9, right1 = ∞
left2 = 7, right2 = 11

Check: left1 ≤ right2? 9 ≤ 11 ✓
Check: left2 ≤ right1? 7 ≤ ∞ ✓

Valid partition!
max_left = max(9, 7) = 9
Median = 9 ✓
```

## Algorithm

### Approach: Binary Search on Smaller Array

**Key Insight**: Instead of merging arrays, use binary search to find the correct partition point where:
- Left partition has `(m + n + 1) / 2` elements
- `max(left_partition) ≤ min(right_partition)`

**Steps**:

1. Ensure `nums1` is the smaller array (swap if needed)
2. Binary search on `nums1` to find partition point `cut1`
3. Calculate corresponding `cut2` in `nums2`: `cut2 = (m + n + 1) / 2 - cut1`
4. Get boundary elements:
   - `left1` = element before cut1 in nums1
   - `right1` = element at cut1 in nums1
   - `left2` = element before cut2 in nums2
   - `right2` = element at cut2 in nums2
5. Check if partition is valid:
   - If `left1 ≤ right2` AND `left2 ≤ right1`: valid partition found
   - If `left1 > right2`: move left (decrease cut1)
   - If `left2 > right1`: move right (increase cut1)
6. Calculate median:
   - If total is odd: `max(left1, left2)`
   - If total is even: `(max(left1, left2) + min(right1, right2)) / 2`

### Pseudocode

```cpp
function findMedianSortedArrays(nums1, nums2):
    if nums1.length > nums2.length:
        swap(nums1, nums2)
    
    m = nums1.length
    n = nums2.length
    low = 0, high = m
    
    while low <= high:
        cut1 = (low + high) / 2
        cut2 = (m + n + 1) / 2 - cut1
        
        left1 = (cut1 == 0) ? -∞ : nums1[cut1 - 1]
        right1 = (cut1 == m) ? +∞ : nums1[cut1]
        left2 = (cut2 == 0) ? -∞ : nums2[cut2 - 1]
        right2 = (cut2 == n) ? +∞ : nums2[cut2]
        
        if left1 <= right2 AND left2 <= right1:
            if (m + n) is odd:
                return max(left1, left2)
            else:
                return (max(left1, left2) + min(right1, right2)) / 2.0
        else if left1 > right2:
            high = cut1 - 1
        else:
            low = cut1 + 1
    
    return 0.0
```

## Complexity Analysis

### Time Complexity: **O(log(min(m, n)))**

**Why?**
- We perform binary search on the smaller array
- Binary search has O(log k) complexity where k is the size of search space
- Search space = size of smaller array = min(m, n)
- Each iteration does O(1) work
- Total: O(log(min(m, n)))

### Space Complexity: **O(1)**

**Why?**
- Only using constant extra space for variables (cut1, cut2, left1, right1, left2, right2)
- No additional data structures
- No recursion stack
- Total: O(1)

## Edge Cases

1. **One array is empty**:
   ```
   nums1 = [], nums2 = [1, 2, 3]
   Output: 2
   ```

2. **Arrays of very different sizes**:
   ```
   nums1 = [1], nums2 = [2, 3, 4, 5, 6]
   Output: 3.5
   ```

3. **All elements in nums1 < all elements in nums2**:
   ```
   nums1 = [1, 2], nums2 = [3, 4]
   Output: 2.5
   ```

4. **All elements in nums1 > all elements in nums2**:
   ```
   nums1 = [3, 4], nums2 = [1, 2]
   Output: 2.5
   ```

5. **Single element in each array**:
   ```
   nums1 = [1], nums2 = [2]
   Output: 1.5
   ```

6. **Duplicate elements**:
   ```
   nums1 = [1, 1], nums2 = [1, 1]
   Output: 1.0
   ```

## Common Mistakes

1. **Not handling edge cases**: Forgetting to handle when cut is at boundaries (0 or array length)
2. **Wrong partition size**: Using `(m + n) / 2` instead of `(m + n + 1) / 2` for left partition
3. **Not ensuring smaller array**: Binary searching on larger array increases time complexity
4. **Integer overflow**: When calculating median for even total, ensure proper type casting
5. **Wrong boundary conditions**: Using `low < high` instead of `low <= high` in binary search

## Related Problems

- [Kth Element of Two Sorted Arrays](../kth-element-two-sorted-arrays/kth-element-two-sorted-arrays.md)
- Merge Two Sorted Arrays
- Find K Pairs with Smallest Sums
- Median of Data Stream

## Key Takeaways

- Binary search can be applied to find partition points, not just search elements
- Always binary search on the smaller array for optimal time complexity
- Partition approach avoids actually merging the arrays
- Handle boundary cases with infinity values (-∞ and +∞)
- The formula `(m + n + 1) / 2` works for both odd and even total lengths

```code```
