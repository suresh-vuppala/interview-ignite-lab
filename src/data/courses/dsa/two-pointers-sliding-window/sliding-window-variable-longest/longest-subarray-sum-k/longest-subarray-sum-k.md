Given an array of positive integers and a value K, find the length of the longest subarray whose sum is ≤ K.

<br>

> Input:
> nums = [1, 2, 1, 0, 1, 1, 0], K = 4

> Output:
> 5

> Explanation:
> Subarray [1, 0, 1, 1, 0] from index 2 to 6 has sum = 3 ≤ 4, length = 5.
> No longer subarray has sum ≤ 4.
> 
> Sliding window process:
> - Expand right, add to sum
> - When sum > K, shrink from left
> - Track maximum window size
> 
> **Key insight:** All values are positive, so expanding always increases sum and shrinking always decreases it — monotonic property enables sliding window.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `1 ≤ nums[i] ≤ 10⁵ (positive integers only)`
- `1 ≤ K ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Entire array sum ≤ K:** Return n
2. **Every element > K:** Return 0 — no valid subarray
3. **Single element = K:** Return 1
4. **Single element > K:** Return 0
5. **K = 0:** No positive subarray can have sum ≤ 0 — return 0
6. **All elements are 1:** Longest subarray is min(K, n)
7. **Large K:** Might include entire array

<br>

---

## Solution: Variable-Size Sliding Window

**Intuition:**
Since all elements are positive, the sum grows as we expand and shrinks as we contract. This monotonic behavior makes sliding window applicable. Expand the right boundary, and when sum exceeds K, shrink from the left.

**Algorithm:**
1. Initialize left = 0, sum = 0, maxLen = 0
2. For right = 0 to n-1:
   - sum += nums[right]
   - While sum > K:
     - sum -= nums[left]
     - left++
   - maxLen = max(maxLen, right - left + 1)
3. Return maxLen

**Why this works:**
- Positive numbers guarantee: adding element always increases sum, removing always decreases
- No need to consider windows we've already shrunk past
- Each element added and removed at most once → O(n)

<br>

### Time Complexity: O(n)
**Why?**
- Right pointer: n steps
- Left pointer: at most n steps total across all iterations
- Total: O(2n) = O(n)

### Space Complexity: O(1) — only variables

<br>
<br>

---

```code```
