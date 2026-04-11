Given an array of integers and an integer M, find the maximum sum of any contiguous subarray whose sum is ≤ M.

<br>

> Input:
> nums = [2, 1, -1, 4, -3], M = 5

> Output:
> 5

> Explanation:
> Subarray [2, 1, -1, 4, -3] has sum = 3 ≤ 5. Subarray [2, 1, -1, 4] has sum = 6 > 5. Subarray [1, -1, 4] has sum = 4. Subarray [2, 1, -1, 3] ... Best: [2, 1, -1, 4, -3] = 3 or [4] = 4 or [2,1,-1,4-3]=3. Actually [2,1,-1,4,-3]=3, [1,-1,4]=4, [4]=4, [2,1]=3, [2,1,-1]=2. Max ≤ 5 is 4.
> 
> **Key insight:** With negatives, sliding window doesn't directly work. Use prefix sums + ordered set (BST). For each right, find smallest prefix sum ≥ prefixSum[right] - M using lower_bound.

<br>



---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `-10⁹ ≤ M ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **All negative, M very large:** Least negative single element
2. **All positive:** Standard maximum subarray with constraint
3. **M = 0:** Longest non-positive subarray sum
4. **Every element > M:** Return max single element ≤ M (or impossible)

<br>

---

## Solution 1: Brute Force — Check All Subarrays

**Intuition:**
For each subarray, compute sum and track maximum ≤ M.

### Time Complexity: O(N²)
**Why?**
- O(N²) subarrays × O(1) for incremental sum

**Detailed breakdown:**
- N = 100,000 → ~5,000,000,000 — TLE

### Space Complexity: O(1)

> **Drawback:**
> Checking all N² subarrays. We can't use sliding window because negatives break monotonicity. Need a smarter approach using prefix sums.

> **Key Insight for Improvement:**
> For subarray sum [i+1..j] = prefix[j] - prefix[i] ≤ M, we need prefix[i] ≥ prefix[j] - M. For each j, find the smallest prefix[i] ≥ prefix[j] - M among i < j. An ordered set with lower_bound gives this in O(log N).

<br>

---

## Solution 2: Prefix Sum + Ordered Set (Optimal)

**Intuition:**
Maintain prefix sums in an ordered set (BST). For each new prefix sum, query for the smallest existing prefix sum ≥ (currentPrefix - M). The difference gives the maximum valid subarray sum.

**Algorithm:**
1. Initialize ordered set with {0} (empty prefix)
2. prefix = 0, maxSum = -∞
3. For each num:
   - prefix += num
   - Find smallest val in set where val ≥ prefix - M (lower_bound)
   - If found: maxSum = max(maxSum, prefix - val) — this is ≤ M
   - Insert prefix into set
4. Return maxSum

### Time Complexity: O(N log N)
**Why?**
- N iterations
- Each iteration: O(log N) for lower_bound + O(log N) for insert
- Total: O(N log N)

**Detailed breakdown:**
- N = 100,000 → ~1,600,000 operations
- Compared to brute: 5,000,000,000 → 1,600,000 (3,125× faster!)

**Example walkthrough:**
```
nums = [2, 1, -1, 4, -3], M = 5
set = {0}, prefix = 0

num=2: prefix=2, find ≥ 2-5=-3 → 0, sum=2-0=2≤5 ✓, set={0,2}
num=1: prefix=3, find ≥ 3-5=-2 → 0, sum=3-0=3≤5 ✓, set={0,2,3}
num=-1: prefix=2, find ≥ 2-5=-3 → 0, sum=2-0=2≤5, set={0,2,2,3}
num=4: prefix=6, find ≥ 6-5=1 → 2, sum=6-2=4≤5 ✓ ★, set={0,2,2,3,6}
num=-3: prefix=3, find ≥ 3-5=-2 → 0, sum=3-0=3≤5, set={0,2,2,3,3,6}

maxSum = 4 ✓
```

### Space Complexity: O(N)
**Why?**
- Ordered set stores N prefix sums

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | All subarrays |
| Prefix + BST | O(N log N) | O(N) | Binary search in ordered prefix sums |

**Recommended Solution:** Prefix Sum + Ordered Set (Solution 2) — O(N log N) time.

**Key Insights:**
1. **Can't use sliding window:** Negatives break monotonicity
2. **Prefix sum reformulation:** subarray sum = prefix[j] - prefix[i]
3. **BST lower_bound:** Find closest valid prefix sum in O(log N)
4. **C++ `set` is ideal:** `lower_bound` is O(log N); Python needs `SortedList`


<br>
<br>

---

```code```
