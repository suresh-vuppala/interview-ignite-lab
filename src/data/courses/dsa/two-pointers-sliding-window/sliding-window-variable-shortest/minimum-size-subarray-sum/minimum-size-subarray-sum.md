Given an array of positive integers and a target sum, find the minimal length of a contiguous subarray whose sum is greater than or equal to target. Return 0 if no such subarray exists.

<br>

> Input:
> target = 7, nums = [2,3,1,2,4,3]

> Output:
> 2

> Explanation:
> The subarray [4,3] has minimal length with sum ≥ 7
> Other valid subarrays: [2,3,2], [3,1,2,4], [2,4,3], etc.
> 
> **Key insight:** Use sliding window - expand right to increase sum, shrink left when sum ≥ target.

<br>



---

## Constraints

- `1 ≤ target ≤ 10⁹`
- `1 ≤ nums.length ≤ 10⁵`
- `1 ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **No valid subarray:** Total sum < target → return 0
2. **Single element ≥ target:** Return 1
3. **Entire array needed:** Sum barely meets target only with all elements
4. **All elements equal:** Need ceil(target / element) elements
5. **Target = 1:** Any single positive element works → return 1
6. **Large target, small elements:** May need many or all elements
7. **Single element array:** Either meets target or doesn't

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check all possible subarrays. For each subarray, calculate sum and check if ≥ target.

**Algorithm:**
1. For each starting position i
2. For each ending position j ≥ i
3. Calculate sum of subarray [i, j]
4. If sum ≥ target, update min length

### Time Complexity: O(n²)
**Why?**
- Two nested loops: O(n²) subarrays
- Sum calculation: O(1) per iteration (incremental)
- Total: O(n²)

### Space Complexity: O(1)
**Why?**
- Only tracking sum and min length
- No additional structures

**Problem:** Checking all subarrays is inefficient.

> **Key Insight for Improvement:**
> Use sliding window. When sum ≥ target, try shrinking from left to find smaller valid window.

<br>

---

## Solution 2: Sliding Window (Optimal)

**Intuition:**
Maintain a window with sum ≥ target. Expand right to increase sum, shrink left while sum still ≥ target to minimize length.

**Algorithm:**
1. Use two pointers: left and right
2. Expand right, add to sum
3. While sum ≥ target:
   - Update min length
   - Shrink from left
4. Return min length (or 0 if not found)

### Time Complexity: O(n)
**Why?**
- Right pointer moves n times: O(n)
- Left pointer moves at most n times total: O(n)
- Each element processed at most twice
- Total: O(n)

**Improvement:**
- Before: O(n²)
- After: O(n)
- Example: n=10000
  - Brute: 100,000,000 operations
  - Sliding: 10,000 operations (10,000× faster!)

### Space Complexity: O(1)
**Why?**
- Only tracking sum, pointers, and min length
- Constant space

<br>

---

## Solution 3: Binary Search + Prefix Sum

**Intuition:**
Build prefix sum array. For each position, use binary search to find smallest j where prefixSum[j] - prefixSum[i] ≥ target.

**Algorithm:**
1. Build prefix sum array
2. For each position i:
   - Binary search for smallest j where sum[i:j] ≥ target
   - Update min length

### Time Complexity: O(n log n)
**Why?**
- Build prefix sum: O(n)
- For each position: binary search O(log n)
- Total: O(n log n)

**Note:** Slower than sliding window but useful when array has negative numbers.

### Space Complexity: O(n)
**Why?**
- Prefix sum array: O(n)

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Checks all subarrays |
| Sliding Window | O(n) | O(1) | Optimal for positive numbers |
| Binary Search | O(n log n) | O(n) | Works with negative numbers |

> **Recommended Solution:** Sliding Window - O(n) time, O(1) space

<br>
<br>

---

```code```
