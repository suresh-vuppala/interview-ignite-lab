Given a binary array nums and integer k, return the maximum number of consecutive 1's if you can flip at most k 0's.

<br>

> Input:
> nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

> Output:
> 6

> Explanation:
> Flip zeros at positions 5 and 10 → [1,1,1,0,0,1,1,1,1,1,1]. Longest consecutive 1's = 6 (indices 5-10).
> 
> **Key insight:** This is "Longest Repeating Character Replacement" with only '1' as the target. Window is valid when number of 0's in window ≤ k. Sliding window: expand right, shrink left when zeros > k.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `0 ≤ k ≤ nums.length`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Longest run of 1's (no flips)
2. **k ≥ count of 0's:** Entire array
3. **All 1's:** Return n regardless of k
4. **All 0's:** Return min(n, k)

<br>

---

## Solution 1: Brute Force — All Subarrays

**Intuition:**
The most straightforward approach. Checking each subarray from scratch.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking each subarray from scratch. Same as character replacement — we should use a sliding window.

> **Key Insight for Improvement:**
> Track zero count in the window. When zeros > k, shrink from left. Window is valid when zeroCount ≤ k.

<br>

---

## Solution 2: Sliding Window — Count Zeros (Optimal)

**Intuition:**
Window is valid when it contains ≤ k zeros. Expand right. If zeros > k, shrink left until zeros ≤ k. Track max window length.

**Algorithm:**
1. left = 0, zeros = 0, maxLen = 0
2. For right = 0 to n-1:
   - If nums[right] == 0 → zeros++
   - While zeros > k: if nums[left] == 0 → zeros--; left++
   - maxLen = max(maxLen, right - left + 1)

### Time Complexity: O(N)
**Why?**
- Right pointer: N iterations
- Left pointer: moves at most N times total
- Total: 2N = O(N)

**Detailed breakdown:**
- N = 100,000 → at most 200,000 operations

**Example walkthrough:**
```
nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

right=0,1,2: all 1's → zeros=0, window grows → len=3
right=3: 0 → zeros=1 ≤ 2 ✓ → len=4
right=4: 0 → zeros=2 ≤ 2 ✓ → len=5
right=5: 0 → zeros=3 > 2 → shrink until zeros ≤ 2
  left=0(1): skip, left=1(1): skip, left=2(1): skip, left=3(0): zeros=2 ✓
  left=4, window=[0,0,1,1,1,1,0] wait... let me redo
  
Actually: shrink removes nums[0]=1→left=1, nums[1]=1→left=2, nums[2]=1→left=3, nums[3]=0→zeros=2→left=4
right=5: window = [0,0,1,1,1,1] wait that has 2 zeros... left=4, window size=2

Let me be precise:
right=5: nums[5]=0, zeros=3. While zeros>2: nums[3]=0→zeros=2, left=4. len=5-4+1=2
right=6: 1, zeros=2, len=3
right=7: 1, len=4
right=8: 1, len=5
right=9: 1, len=6 ★
right=10: 0, zeros=3>2 → shrink: nums[4]=0→zeros=2, left=5. len=10-5+1=6

maxLen = 6 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Check all windows |
| Sliding Window | O(N) | O(1) | Track zero count, shrink when > k |

**Recommended Solution:** Sliding Window (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Reframe:** "Flip k zeros" = "Find longest window with ≤ k zeros"
2. **Same as Character Replacement:** Target char = 1, replacements = zeros in window
3. **Binary array simplifies:** Only track zero count (not full frequency)


<br>
<br>

---

```code```
