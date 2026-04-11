Given an integer array nums and integer k, return the count of subarrays with exactly k distinct integers.

<br>

> Input:
> nums = [1, 2, 1, 2, 3], k = 2

> Output:
> 7

> Explanation:
> [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2] — all have exactly 2 distinct integers.
> 
> **Key insight:** "Exactly K" = "At most K" - "At most K-1". Each "at most" is a standard sliding window problem.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 2 × 10⁴`
- `1 ≤ nums[i], k ≤ nums.length`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Count subarrays with all same elements
2. **k = n:** Only if all elements are distinct → 1 subarray
3. **All same elements:** Only k=1 gives non-zero result

<br>

---

## Solution 1: Brute Force

### Time Complexity: O(N²)

> **Drawback:**
> Checking each subarray's distinct count independently. Can't directly use sliding window for "exactly K" because shrinking past exact K means we might miss valid windows.

> **Key Insight for Improvement:**
> Decompose: exactlyK(k) = atMostK(k) - atMostK(k-1). "At most K distinct" is a standard sliding window. Run it twice and subtract.

<br>

---

## Solution 2: At Most K Decomposition (Optimal)

**Intuition:**
atMostK(k) counts all subarrays with ≤ k distinct. Subtracting atMostK(k-1) leaves only subarrays with exactly k distinct.

**Algorithm:**
1. Define atMostK(nums, k): sliding window counting subarrays with ≤ k distinct
2. Return atMostK(nums, k) - atMostK(nums, k-1)

**atMostK helper:**
- left = 0, freq = {}, count = 0
- For right = 0 to n-1:
  - freq[nums[right]]++
  - While freq.size() > k: freq[nums[left]]--, if 0→delete, left++
  - count += right - left + 1

### Time Complexity: O(N)
**Why?**
- Two calls to atMostK, each O(N)
- Total: 2 × O(N) = O(N)

**Detailed breakdown:**
- N = 20,000 → ~80,000 operations (two sliding window passes)

**Example walkthrough:**
```
nums = [1, 2, 1, 2, 3], k = 2

atMostK(2): count subarrays with ≤ 2 distinct
  [1]=1, [1,2]=2, [2]=1, [2,1]=2, [1]=1, [1,2]=2, [2]=1, [2,3]=2, [3]=1, [1,2,1]=3→shrink...
  = 12

atMostK(1): count subarrays with ≤ 1 distinct
  = 5 (subarrays [1],[2],[1],[2],[3])

exactlyK(2) = 12 - 5 = 7 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(N) | Count distinct per subarray |
| At Most K | O(N) | O(N) | exactly(k) = atMost(k) - atMost(k-1) |

**Recommended Solution:** At Most K Decomposition — O(N) time.

**Key Insights:**
1. **Decomposition trick:** exactly(k) = atMost(k) - atMost(k-1)
2. **atMostK is standard:** Sliding window with freq map
3. **Reusable pattern:** Works for any "exactly K" → "at most K" decomposition


<br>
<br>

---

```code```
