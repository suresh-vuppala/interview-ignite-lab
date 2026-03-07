## Problem Statement

Given two sorted arrays `nums1` and `nums2` of sizes `m` and `n` respectively, find the **kth smallest element** in the combined sorted array.

The overall run time complexity should be **O(log(min(m, n)))**.

**Note**: k is 1-indexed (k = 1 means the smallest element).

## Examples

### Example 1
```
Input: nums1 = [2, 3, 6, 7, 9], nums2 = [1, 4, 8, 10], k = 5
Output: 6
Explanation: Merged array = [1, 2, 3, 4, 6, 7, 8, 9, 10]
             5th element (index 4) = 6
```

### Example 2
```
Input: nums1 = [100, 112, 256, 349, 770], nums2 = [72, 86, 113, 119, 265, 445], k = 7
Output: 256
Explanation: Merged array = [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770]
             7th element (index 6) = 256
```

### Example 3
```
Input: nums1 = [1, 3, 5], nums2 = [2, 4, 6], k = 4
Output: 4
Explanation: Merged array = [1, 2, 3, 4, 5, 6]
             4th element (index 3) = 4
```

## Visual Walkthrough

### Example: nums1 = [2, 3, 6, 7, 9], nums2 = [1, 4, 8, 10], k = 5

```
Merged array: [1, 2, 3, 4, 6, 7, 8, 9, 10]
               0  1  2  3  4  5  6  7   8

k = 5 means we need the 5th element (index 4) = 6
```

### Binary Search Partition Approach

```
nums1 = [2, 3, 6, 7, 9]  (m = 5)
nums2 = [1, 4, 8, 10]    (n = 4)
k = 5

We need to partition arrays such that:
- Left partition has exactly k elements
- max(left) ≤ min(right)
- The kth element = max(left)

Step 1: Binary search on nums2 (smaller array)
Try cut2 = 2 (take [1, 4] from nums2)
Then cut1 = k - cut2 = 5 - 2 = 3 (take [2, 3, 6] from nums1)

nums1: [2, 3, 6] | [7, 9]
nums2: [1, 4] | [8, 10]

Left partition: [1, 2, 3, 4, 6]  (5 elements)
Right partition: [7, 8, 9, 10]

left1 = 6, right1 = 7
left2 = 4, right2 = 8

Check: left1 ≤ right2? 6 ≤ 8 ✓
Check: left2 ≤ right1? 4 ≤ 7 ✓

Valid partition!
kth element = max(left1, left2) = max(6, 4) = 6 ✓
```

### Another Example: k = 3

```
nums1 = [2, 3, 6, 7, 9]
nums2 = [1, 4, 8, 10]
k = 3

Try cut2 = 1 (take [1] from nums2)
Then cut1 = k - cut2 = 3 - 1 = 2 (take [2, 3] from nums1)

nums1: [2, 3] | [6, 7, 9]
nums2: [1] | [4, 8, 10]

Left partition: [1, 2, 3]  (3 elements)
Right partition: [4, 6, 7, 8, 9, 10]

left1 = 3, right1 = 6
left2 = 1, right2 = 4

Check: left1 ≤ right2? 3 ≤ 4 ✓
Check: left2 ≤ right1? 1 ≤ 6 ✓

Valid partition!
kth element = max(left1, left2) = max(3, 1) = 3 ✓

Verify: Merged = [1, 2, 3, 4, 6, 7, 8, 9, 10]
        3rd element (index 2) = 3 ✓
```

### Step-by-Step Binary Search

```
nums1 = [2, 3, 6, 7, 9]
nums2 = [1, 4, 8, 10]
k = 5

Binary search on nums2 (smaller array):
low = 0, high = 4

Iteration 1: cut2 = (0 + 4) / 2 = 2
cut1 = 5 - 2 = 3

nums1: [2, 3, 6] | [7, 9]
nums2: [1, 4] | [8, 10]

left1 = 6, right1 = 7
left2 = 4, right2 = 8

Check: 6 ≤ 8 ✓ and 4 ≤ 7 ✓
Found! Return max(6, 4) = 6
```

### Example with Adjustment Needed

```
nums1 = [1, 3, 5, 7, 9]
nums2 = [2, 4, 6, 8, 10]
k = 6

Try cut2 = 2 (take [2, 4] from nums2)
cut1 = 6 - 2 = 4 (take [1, 3, 5, 7] from nums1)

nums1: [1, 3, 5, 7] | [9]
nums2: [2, 4] | [6, 8, 10]

left1 = 7, right1 = 9
left2 = 4, right2 = 6

Check: left1 ≤ right2? 7 ≤ 6 ❌

left1 > right2, so we took too many from nums1
Need fewer from nums1, more from nums2
Move right: low = cut2 + 1 = 3

Try cut2 = 3 (take [2, 4, 6] from nums2)
cut1 = 6 - 3 = 3 (take [1, 3, 5] from nums1)

nums1: [1, 3, 5] | [7, 9]
nums2: [2, 4, 6] | [8, 10]

left1 = 5, right1 = 7
left2 = 6, right2 = 8

Check: left1 ≤ right2? 5 ≤ 8 ✓
Check: left2 ≤ right1? 6 ≤ 7 ✓

Valid partition!
kth element = max(5, 6) = 6 ✓

Verify: Merged = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        6th element (index 5) = 6 ✓
```

## Algorithm

### Approach: Binary Search on Smaller Array

**Key Insight**: Use binary search to find the partition point where exactly k elements are on the left side.

**Steps**:

1. Ensure we binary search on the smaller array (swap if needed)
2. Set search range: `low = max(0, k - n)` to `high = min(k, m)`
3. For each mid point `cut1` in nums1:
   - Calculate `cut2 = k - cut1` in nums2
   - Get boundary elements (left1, right1, left2, right2)
   - Check if partition is valid
4. If valid: return `max(left1, left2)`
5. If `left1 > right2`: move left (decrease cut1)
6. If `left2 > right1`: move right (increase cut1)

### Pseudocode

```cpp
function kthElement(nums1, nums2, k):
    m = nums1.length
    n = nums2.length
    
    // Ensure nums1 is smaller
    if m > n:
        return kthElement(nums2, nums1, k)
    
    // Binary search bounds
    low = max(0, k - n)
    high = min(k, m)
    
    while low <= high:
        cut1 = (low + high) / 2
        cut2 = k - cut1
        
        left1 = (cut1 == 0) ? -∞ : nums1[cut1 - 1]
        right1 = (cut1 == m) ? +∞ : nums1[cut1]
        left2 = (cut2 == 0) ? -∞ : nums2[cut2 - 1]
        right2 = (cut2 == n) ? +∞ : nums2[cut2]
        
        if left1 <= right2 AND left2 <= right1:
            return max(left1, left2)
        else if left1 > right2:
            high = cut1 - 1
        else:
            low = cut1 + 1
    
    return -1
```

### Important Boundary Calculations

```cpp
// Why low = max(0, k - n)?
// If k > n, we must take at least (k - n) elements from nums1

// Why high = min(k, m)?
// We can't take more than k elements from nums1
// We also can't take more than m elements (size of nums1)

Example:
nums1 = [1, 2, 3], nums2 = [4, 5], k = 4
m = 3, n = 2

low = max(0, 4 - 2) = max(0, 2) = 2
high = min(4, 3) = 3

We must take at least 2 from nums1 (since nums2 only has 2)
We can take at most 3 from nums1 (its size)
```

## Complexity Analysis

### Time Complexity: **O(log(min(m, n)))**

**Why?**
- Binary search on the smaller array
- Each iteration: O(1) operations
- Search space: min(m, n)
- Total: O(log(min(m, n)))

### Space Complexity: **O(1)**

**Why?**
- Only constant extra variables
- No additional data structures
- No recursion (iterative approach)
- Total: O(1)

## Edge Cases

1. **k = 1 (smallest element)**:
   ```
   nums1 = [2, 3, 4], nums2 = [1, 5, 6], k = 1
   Output: 1
   ```

2. **k = m + n (largest element)**:
   ```
   nums1 = [1, 2], nums2 = [3, 4], k = 4
   Output: 4
   ```

3. **One array is empty**:
   ```
   nums1 = [], nums2 = [1, 2, 3], k = 2
   Output: 2
   ```

4. **k requires all elements from one array**:
   ```
   nums1 = [1, 2], nums2 = [3, 4, 5, 6], k = 5
   Output: 5 (need all of nums1 and 3 from nums2)
   ```

5. **All elements in nums1 < all in nums2**:
   ```
   nums1 = [1, 2, 3], nums2 = [4, 5, 6], k = 4
   Output: 4
   ```

6. **Duplicate elements**:
   ```
   nums1 = [1, 1, 2], nums2 = [1, 2, 2], k = 3
   Output: 1
   ```

## Common Mistakes

1. **Wrong boundary calculation**: Not using `max(0, k - n)` and `min(k, m)` for search bounds
2. **Off-by-one errors**: Confusing 0-indexed vs 1-indexed k
3. **Not handling edge cases**: When cut is at array boundaries
4. **Wrong partition check**: Forgetting to check both `left1 ≤ right2` AND `left2 ≤ right1`
5. **Not ensuring smaller array**: Binary searching on larger array increases complexity
6. **Invalid k values**: Not validating that `1 ≤ k ≤ m + n`

## Comparison with Median Problem

| Aspect | Median | Kth Element |
|--------|--------|-------------|
| Target | Middle element(s) | Any kth element |
| Partition size | `(m + n + 1) / 2` | `k` |
| Return value | Single or average | Single element |
| Search bounds | `[0, m]` | `[max(0, k-n), min(k, m)]` |

## Related Problems

- [Median of Two Sorted Arrays](../median-two-sorted-arrays/median-two-sorted-arrays.md)
- Kth Smallest Element in Sorted Matrix
- Find K Pairs with Smallest Sums
- Merge K Sorted Arrays

## Key Takeaways

- Binary search on partition points, not element values
- Always search on the smaller array for optimal complexity
- Boundary calculations are crucial: `low = max(0, k - n)`, `high = min(k, m)`
- The kth element is `max(left1, left2)` when partition is valid
- Handle edge cases with infinity values for boundaries
- This is a generalization of the median problem (median is k = (m+n+1)/2)

```code```
