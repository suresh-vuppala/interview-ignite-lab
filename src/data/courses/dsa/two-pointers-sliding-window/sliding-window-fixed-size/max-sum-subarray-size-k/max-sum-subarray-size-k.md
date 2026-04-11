Given an array of integers and a number k, find the maximum sum of any contiguous subarray of size k.

<br>

> Input:
> arr = [2, 1, 5, 1, 3, 2], k = 3

> Output:
> 9

> Explanation:
> All subarrays of size 3:
> - [2,1,5] → sum = 8
> - [1,5,1] → sum = 7
> - [5,1,3] → sum = 9 (maximum)
> - [1,3,2] → sum = 6
> 
> **Key insight:** Sliding window avoids recalculating overlapping sums.

<br>



---

## Constraints

- `1 ≤ k ≤ nums.length ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **k equals array length:** Only one window — return total sum
2. **k = 1:** Return the maximum element
3. **All negative:** Max sum is still the least negative window
4. **All same elements:** All windows have equal sum
5. **Single element array, k=1:** Return that element
6. **Array with zeros:** Zeros don't contribute to sum
7. **Large k with alternating pos/neg:** Must check all windows

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check every possible subarray of size k and track the maximum sum.

**Algorithm:**
1. For each starting position i (0 to n-k)
2. Calculate sum of k elements starting at i
3. Update maximum if current sum is larger

### Time Complexity: O(n×k)
**Why?**
- Outer loop: n-k+1 iterations
- Inner loop: k additions per iteration
- Total: (n-k+1) × k ≈ O(n×k)

**Example:** n=1000, k=100 → 100,000 operations

### Space Complexity: O(1)
**Why?**
- Only tracking max sum and current sum
- No additional data structures

**Problem:** Recalculating sum for each window is inefficient.

> **Key Insight for Improvement:**
> When sliding window right by 1, only 2 elements change: remove leftmost, add rightmost. Reuse previous sum!

<br>

---

## Solution 2: Sliding Window (Optimal)

**Intuition:**
Calculate first window sum, then slide window by removing left element and adding right element.

**Algorithm:**
1. Calculate sum of first k elements
2. Initialize maxSum with first window sum
3. For each new position:
   - Subtract element leaving window
   - Add element entering window
   - Update maxSum if needed

### Time Complexity: O(n)
**Why?**
- Calculate first window: O(k)
- Slide window n-k times: O(n-k)
- Each slide: O(1) work
- Total: O(k) + O(n-k) = O(n)

**Improvement:**
- Before: O(n×k) = 100,000 operations
- After: O(n) = 1,000 operations (100× faster!)

### Space Complexity: O(1)
**Why?**
- Only storing windowSum and maxSum
- No arrays or additional structures

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n×k) | O(1) | Recalculates each window |
| Sliding Window | O(n) | O(1) | Optimal - single pass |

> **Recommended Solution:** Sliding Window - O(n) time, O(1) space

<br>
<br>

---

```code```
