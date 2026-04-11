Given an integer array nums, find all unique triplets [nums[i], nums[j], nums[k]] such that i ≠ j ≠ k and nums[i] + nums[j] + nums[k] = 0.

<br>

> Input:
> nums = [-1, 0, 1, 2, -1, -4]

> Output:
> [[-1, -1, 2], [-1, 0, 1]]

> Explanation:
> -1 + -1 + 2 = 0 and -1 + 0 + 1 = 0. No other unique triplets sum to zero.
> 
> **Key insight:** Sort + fix one element + two-pointer for the remaining pair. Skip duplicates to avoid repeated triplets.

<br>



---

## Constraints

- `3 ≤ nums.length ≤ 3000`
- `-10⁵ ≤ nums[i] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **All zeros:** [0,0,0] → [[0,0,0]]
2. **No solution:** [1,2,3] → []
3. **Many duplicates:** [-1,-1,-1,0,0,1,1] → handle carefully
4. **Minimum length:** [a,b,c] → one triplet check

<br>

---

## Solution 1: Brute Force — Check All Triplets

**Intuition:**
Try every combination of three elements. Use a set to avoid duplicate triplets.

**Algorithm:**
1. Sort the array
2. For each i, j, k (i < j < k):
   - If nums[i] + nums[j] + nums[k] == 0 → add sorted triplet to set
3. Return unique triplets

### Time Complexity: O(N³)
**Why?**
- Three nested loops: N × N × N
- N = 3000 → 27,000,000,000 — TLE

**Detailed breakdown:**
- C(3000, 3) ≈ 4.5 billion triplets

### Space Complexity: O(1) extra
**Why?**
- Only using set for dedup (could be O(N²) for results)

> **Drawback:**
> O(N³) is far too slow for N=3000. The inner two loops essentially solve "Two Sum" for each fixed element — but we're not leveraging the sorted order.

> **Key Insight for Improvement:**
> Sort the array. Fix nums[i] with the outer loop. For the remaining two elements, use the Two Sum Sorted approach (two pointers from both ends). This reduces the inner loops from O(N²) to O(N). Total: O(N²). Skip duplicates by checking if current == previous.

<br>

---

## Solution 2: Sort + Two Pointers (Optimal)

**Intuition:**
Sort first. For each fixed element nums[i], find pairs (left, right) where nums[left] + nums[right] = -nums[i] using two pointers. Skip duplicates at all three levels.

**Algorithm:**
1. Sort the array
2. For each i from 0 to n-3:
   - Skip if nums[i] == nums[i-1] (duplicate first element)
   - If nums[i] > 0 → break (sorted: no way to reach 0)
   - left = i+1, right = n-1
   - While left < right:
     - sum = nums[i] + nums[left] + nums[right]
     - If sum == 0 → add triplet, skip duplicate lefts, skip duplicate rights, advance both
     - If sum < 0 → left++
     - If sum > 0 → right--

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner two-pointer: O(N) per outer iteration
- Total: N × N = O(N²)

**Detailed breakdown:**
- N = 3000 → ~9,000,000 operations
- Compared to brute: 4,500,000,000 → 9,000,000 (500× faster!)

**Example walkthrough:**
```
nums = [-1, 0, 1, 2, -1, -4]
sorted: [-4, -1, -1, 0, 1, 2]

i=0: nums[0]=-4, target=4, left=1, right=5
  -1+2=1 < 4 → left++
  -1+2=1 < 4 → left++
  0+2=2 < 4 → left++
  1+2=3 < 4 → left++, left≥right → stop

i=1: nums[1]=-1, target=1, left=2, right=5
  -1+2=1 == 1 → FOUND [-1,-1,2] ✓
  skip dup left, skip dup right → left=3, right=4
  0+1=1 == 1 → FOUND [-1,0,1] ✓

i=2: nums[2]=-1 == nums[1] → SKIP duplicate

i=3: nums[3]=0 → target=0, left=4, right=5
  1+2=3 > 0 → right--, right<left → stop

Result: [[-1,-1,2], [-1,0,1]] ✓
```

### Space Complexity: O(1) extra
**Why?**
- Only pointer variables (result storage doesn't count)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N³) | O(1) | Check all triplets |
| Sort + Two Ptr | O(N²) | O(1) | Fix one + two-pointer for pair |

**Recommended Solution:** Sort + Two Pointers (Solution 2) — O(N²) time, O(1) space.

**Key Insights:**
1. **Reduce to Two Sum:** Fix one element, solve Two Sum for the remaining pair
2. **Sorted array enables:** Two-pointer convergence and duplicate skipping
3. **Three levels of dedup:** Skip duplicate i, skip duplicate left, skip duplicate right
4. **Early termination:** If nums[i] > 0, no triplet possible (all remaining are positive)


<br>
<br>

---

```code```
