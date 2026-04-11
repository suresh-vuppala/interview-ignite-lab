Given an array of integers and a window size k, find if any contiguous subarray of size k has a given target sum.

<br>

> Input:
> nums = [1, 2, 3, 4, 5], k = 3, target = 9

> Output:
> true

> Explanation:
> Subarray [2, 3, 4] has sum = 9. Window of size 3 found.
> 
> **Key insight:** Adjacent windows of size k share k-1 elements. Slide by subtracting the leaving element and adding the entering element — O(1) per transition.

<br>



---

## Constraints

- `1 ≤ k ≤ n ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **k = n:** Only one window — check total sum
2. **k = 1:** Check if any element equals target
3. **All same elements:** Target must be k × element
4. **Negative numbers:** Sum can decrease as window slides

<br>

---

## Solution 1: Brute Force — Recompute Each Window

**Intuition:**
For each starting position i, sum the k elements from i to i+k-1.

**Algorithm:**
1. For each i from 0 to n-k:
   - Sum nums[i..i+k-1]
   - If sum == target → return true
2. Return false

### Time Complexity: O(N × K)
**Why?**
- (N - K + 1) windows
- Each window: K additions
- Total: (N-K+1) × K ≈ O(N × K)

**Detailed breakdown:**
- N = 100,000, K = 1,000 → 100,000 × 1,000 = 100,000,000 operations
- Adjacent windows share K-1 elements — wasted recomputation

### Space Complexity: O(1)
**Why?**
- Only sum variable and loop indices

> **Drawback:**
> We recalculate the sum from scratch for every window. Adjacent windows differ by only 2 elements (one leaves, one enters), yet we're re-adding all K elements each time.

> **Key Insight for Improvement:**
> Maintain a running sum. When sliding from window [i..i+k-1] to [i+1..i+k]: subtract nums[i] (leaving), add nums[i+k] (entering). Each slide is O(1) instead of O(K).

<br>

---

## Solution 2: Sliding Window — Running Sum (Optimal)

**Intuition:**
Compute the sum of the first window. Then slide: subtract the element that leaves, add the element that enters. Each transition is O(1).

**Algorithm:**
1. Compute sum of first window: sum = nums[0] + ... + nums[k-1]
2. If sum == target → return true
3. For i = k to n-1:
   - sum += nums[i] - nums[i-k] (slide: add entering, subtract leaving)
   - If sum == target → return true
4. Return false

### Time Complexity: O(N)
**Why?**
- First window: O(K)
- Remaining slides: O(N-K), each O(1)
- Total: K + (N-K) = O(N)

**Detailed breakdown:**
- N = 100,000 → 100,000 operations (regardless of K)
- Compared to brute: 100,000,000 → 100,000 (1,000× faster for K=1,000!)

**Example walkthrough:**
```
nums = [1, 2, 3, 4, 5], k = 3, target = 9

First window: sum = 1+2+3 = 6 ≠ 9
Slide: sum = 6 - 1 + 4 = 9 == 9 → return true ✓
```

### Space Complexity: O(1)
**Why?**
- Only running sum variable

**Why this is optimal:**
- Must examine each element at least once: O(N) minimum
- O(1) space — can't do better

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N×K) | O(1) | Recompute sum per window |
| Sliding Window | O(N) | O(1) | Running sum — O(1) per slide |

**Recommended Solution:** Sliding Window (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Fixed-size window pattern:** Add entering element, subtract leaving element
2. **O(1) transition:** Adjacent windows share K-1 elements — only 2 change
3. **Foundation:** This is the simplest sliding window — builds to variable-size windows


<br>
<br>

---

```code```
