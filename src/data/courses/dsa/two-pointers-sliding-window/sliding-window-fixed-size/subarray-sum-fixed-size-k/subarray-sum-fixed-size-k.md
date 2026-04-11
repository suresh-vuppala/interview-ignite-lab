Given an array of integers and a number k, find all subarrays of size k and their sums.

<br>

> Input:
> arr = [1, 2, 3, 4, 5, 6], k = 3

> Output:
> [[1,2,3,6], [2,3,4,9], [3,4,5,12], [4,5,6,15]]

> Explanation:
> All subarrays of size 3 with their sums:
> - [1,2,3] → sum = 6
> - [2,3,4] → sum = 9
> - [3,4,5] → sum = 12
> - [4,5,6] → sum = 15
> 
> **Key insight:** Use sliding window to avoid recalculating sum from scratch.

<br>



---

## Constraints

- `1 ≤ k ≤ nums.length ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **k equals array length:** Only one subarray
2. **k = 1:** Each element is its own subarray
3. **All zeros:** All sums are 0
4. **Single element, k=1:** One subarray with that element
5. **Negative numbers:** Sums can be negative
6. **Large array:** Must use O(1) sliding, not O(k) per window

<br>

---

## Solution 1: Brute Force

**Intuition:**
For each possible starting position, calculate the sum of k consecutive elements by iterating through them.

**Algorithm:**
1. Loop through array from index 0 to n-k
2. For each starting position, sum next k elements
3. Store subarray and sum in result

### Time Complexity: O(n×k)
**Why?**
- Outer loop: n-k+1 iterations
- Inner loop: k iterations per subarray
- Total: (n-k+1) × k ≈ O(n×k)

### Space Complexity: O(1)
**Why?**
- Only storing result, no extra data structures
- Excluding output space: O(1)

**Problem:** Recalculating sum for overlapping elements is wasteful.

> **Key Insight for Improvement:**
> Adjacent windows share k-1 elements. Instead of recalculating entire sum, remove leftmost element and add new rightmost element.

<br>

---

## Solution 2: Sliding Window (Optimal)

**Intuition:**
Maintain a window of size k. When sliding right, subtract the element leaving the window and add the new element entering.

**Algorithm:**
1. Calculate sum of first k elements
2. Store first window result
3. Slide window: subtract arr[i-k], add arr[i]
4. Store each window result

### Time Complexity: O(n)
**Why?**
- Single pass through array
- Each element added once, removed once
- Constant work per element
- Total: O(n)

**Improvement:**
- Before: O(n×k)
- After: O(n)
- Example: n=1000, k=100
  - Brute force: 100,000 operations
  - Sliding window: 1,000 operations (100× faster!)

### Space Complexity: O(1)
**Why?**
- Only tracking window sum
- No additional data structures
- Excluding output: O(1)

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n×k) | O(1) | Recalculates overlapping sums |
| Sliding Window | O(n) | O(1) | Optimal - reuses previous sum |

> **Recommended Solution:** Sliding Window - O(n) time, O(1) space

<br>
<br>

---

```code```
