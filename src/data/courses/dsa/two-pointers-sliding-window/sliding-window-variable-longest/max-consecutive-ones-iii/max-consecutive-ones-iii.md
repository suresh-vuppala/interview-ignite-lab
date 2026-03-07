Given a binary array and an integer k, find the maximum number of consecutive 1's if you can flip at most k 0's to 1's.

<br>

> Input:
> nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

> Output:
> 6

> Explanation:
> Flip the two 0's at indices 9 and 10 to get [1,1,1,0,0,0,1,1,1,1,1,1]
> The longest sequence of 1's is from index 6 to 11 (length 6)
> 
> **Key insight:** This is equivalent to finding longest subarray with at most k zeros.

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check all possible subarrays. Count zeros in each. If zeros ≤ k, it's valid.

**Algorithm:**
1. For each starting position i
2. For each ending position j ≥ i
3. Count zeros in subarray [i, j]
4. If zeros ≤ k, update max length

### Time Complexity: O(n²)
**Why?**
- Two nested loops: O(n²) subarrays
- Counting zeros: O(1) per iteration (incremental)
- Total: O(n²)

### Space Complexity: O(1)
**Why?**
- Only tracking zero count and max length
- No additional structures

**Problem:** Checking all subarrays is inefficient.

> **Key Insight for Improvement:**
> Use sliding window. Maintain a window with at most k zeros. Expand right, shrink left when zeros > k.

<br>

---

## Solution 2: Sliding Window

**Intuition:**
Maintain a window with at most k zeros. When zeros exceed k, shrink from left until valid again.

**Algorithm:**
1. Use two pointers: left and right
2. Expand right, count zeros
3. While zeros > k:
   - If nums[left] == 0, decrement zero count
   - Move left forward
4. Update max length

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
- Only tracking zero count and pointers
- Constant space

> **Key Insight for Improvement:**
> Instead of shrinking when invalid, we can maintain window size and only expand when valid. This avoids unnecessary shrinking.

<br>

---

## Solution 3: Optimized Sliding Window (Fixed Window Growth)

**Intuition:**
Once we find a valid window of size x, we only care about windows ≥ x. Keep window size and slide it, only expanding when valid.

**Algorithm:**
1. Track zeros in current window
2. Expand right always
3. If zeros > k, move left (maintain window size)
4. If zeros ≤ k, window grows (don't move left)
5. Final window size is the answer

### Time Complexity: O(n)
**Why?**
- Single pass through array
- Each pointer moves at most n times
- Constant work per iteration

### Space Complexity: O(1)
**Why?**
- Only tracking zero count
- Constant space

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Checks all subarrays |
| Sliding Window | O(n) | O(1) | Shrinks when invalid |
| Optimized Window | O(n) | O(1) | Maintains window size |

> **Recommended Solution:** Sliding Window - O(n) time, O(1) space

<br>
<br>

---

```code```
