Given an unsorted array and a target difference k, find if there exists a pair of elements with difference equal to k.

<br>

> Input:
> nums = [1, 5, 3, 4, 2], k = 2

> Output:
> true (pair: 1,3 or 3,5 etc.)

> Explanation:
> 3 - 1 = 2, 5 - 3 = 2. Multiple valid pairs exist.
> 
> **Key insight:** Sort + two same-direction pointers. If diff < k → advance right (increase diff). If diff > k → advance left (decrease diff). Both move forward only.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Find duplicates
2. **No valid pair:** Return false
3. **Negative numbers:** Differences still work with sorted array
4. **Single element:** No pair possible

<br>

---

## Solution 1: Brute Force — Check All Pairs

**Intuition:**
Check every pair (i,j) where i ≠ j. If |nums[i] - nums[j]| == k → found.

### Time Complexity: O(N²)
**Why?**
- N(N-1)/2 pairs

**Detailed breakdown:**
- N = 100,000 → ~5 billion comparisons — TLE

### Space Complexity: O(1)

> **Drawback:**
> Checking all O(N²) pairs. We're not leveraging any ordering. If the array were sorted, we could use two pointers to find the pair in one pass.

> **Key Insight for Improvement:**
> Sort the array. Use two pointers i and j (both starting at the beginning, j > i). If nums[j]-nums[i] < k → advance j (increase diff). If > k → advance i (decrease diff). If == k → found. Both pointers only move forward → O(N).

<br>

---

## Solution 2: Sort + Two Pointers (Optimal for O(1) space)

**Intuition:**
After sorting, maintain two pointers moving forward. The difference between them determines which to advance.

**Algorithm:**
1. Sort the array
2. i = 0, j = 1
3. While i < n and j < n:
   - If i == j → j++ (can't use same element)
   - diff = nums[j] - nums[i]
   - If diff == k → return true
   - If diff < k → j++ (need larger diff)
   - If diff > k → i++ (need smaller diff)

### Time Complexity: O(N log N)
**Why?**
- Sort: O(N log N)
- Two-pointer pass: O(N)
- Total: O(N log N) dominated by sort

**Detailed breakdown:**
- N = 100,000 → ~1.6M sort + 100K scan = ~1.7M operations
- Compared to brute: 5,000,000,000 → 1,700,000 (2,941× faster!)

**Example walkthrough:**
```
nums = [1, 5, 3, 4, 2], k = 2
sorted: [1, 2, 3, 4, 5]
i=0, j=1

diff = 2-1 = 1 < 2 → j=2
diff = 3-1 = 2 == 2 → return true ✓
```

### Space Complexity: O(1) extra
**Why?**
- In-place sort, two pointer variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Check all pairs |
| Sort + Two Ptr | O(N log N) | O(1) | Sorted difference scan |

**Recommended Solution:** Sort + Two Pointers — O(N log N) time, O(1) space.

**Key Insights:**
1. **Same-direction pointers:** Unlike Two Sum where pointers converge from ends, Two Difference uses both pointers moving forward
2. **Why same direction?** Difference increases when j moves right and decreases when i moves right — both increase monotonically in sorted array
3. **Alternative:** Hash set for O(N) time / O(N) space


<br>
<br>

---

```code```
