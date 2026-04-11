Find the length of the longest subarray whose sum is ≤ K. Array contains only positive integers.

<br>

> Input: nums = [1, 2, 3, 4, 5], k = 10
> Output: 4 (subarray [1,2,3,4] has sum 10 ≤ 10)

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `1 ≤ nums[i] ≤ 10⁵`
- `1 ≤ k ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Entire array sum ≤ k:** Return n
2. **Each element > k:** Return 0
3. **Single element ≤ k:** Return 1

<br>

---

## Solution 1: Brute Force

**Intuition:** Check all subarrays, track longest with sum ≤ k.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Sliding Window (Optimal)

**Intuition:**
Expand window by moving right. When sum exceeds k, shrink from left. Track maximum window size.

**Algorithm:**
1. left = 0, sum = 0, maxLen = 0
2. For right = 0 to n-1:
   - sum += nums[right]
   - While sum > k → sum -= nums[left], left++
   - maxLen = max(maxLen, right - left + 1)

**Why sliding window works:** All elements are positive, so expanding always increases sum and shrinking always decreases it. The window is monotonically adjustable.

### Time Complexity: O(n) — each element visited at most twice
### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all subarrays |
| Sliding Window | O(n) | O(1) | Shrink when sum exceeds k |

<br>
<br>

---

```code```
