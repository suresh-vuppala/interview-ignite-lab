Subset sum for large N using Meet in the Middle.

<br>

> Large N (up to 40) where 2^N is too slow
>
> **Key insight:** Split array in half. Generate all subset sums for each half (2^(N/2) each). Sort one half, binary search for complement.

<br>

---

## Constraints
- 1 ≤ N ≤ 40
- -10⁹ ≤ nums[i] ≤ 10⁹

<br>

---

## All Possible Edge Cases
1. **N ≤ 20: standard DP works
2. **20 < N ≤ 40: must use meet-in-middle
3. **Target = 0: empty subset**

<br>

---

## Solution 1: Standard DP/recursion

**Intuition:**
The most straightforward approach. 2^40 is too large.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> 2^40 is too large.

> **Key Insight for Improvement:**
> Split in half → 2 × 2^20 ≈ 2M operations. Sort one half, binary search for (target - sum) from other half.

<br>

---

## Solution 2: Meet in the Middle (Optimal)

**Intuition:** Split array in half. Generate all subset sums for each half (2^(N/2) each). Sort one half, binary search for complement.

**Algorithm:**
1. Split array into left half and right half
2. Generate all subset sums for left: O(2^(N/2))
3. Generate all subset sums for right: O(2^(N/2))
4. Sort right sums
5. For each left sum: binary search for (target - left_sum) in right

### Time Complexity: O(2^(N/2) × N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
N=40: 2^20 ≈ 1M per half. Total ≈ 2M operations vs 2^40 ≈ 1T
```

### Space Complexity: O(2^(N/2))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Standard DP/recursion | O(2^N) | Varies | Baseline |
| Meet in the Middle | O(2^(N/2) × N) | O(2^(N/2)) | Optimal |

**Recommended Solution:** Meet in the Middle

**Key Insights:**
1. **Square root trick:** 2^(N/2) instead of 2^N
2. **Binary search for complement:** Efficient matching
3. **N up to 40:** Standard DP can't handle, MITM can

<br><br>

---

```code```
