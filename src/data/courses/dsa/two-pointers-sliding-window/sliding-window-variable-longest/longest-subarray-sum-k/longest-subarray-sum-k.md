Given an array of integers (may include negatives) and a target sum k, find the length of the longest subarray whose sum equals k.

<br>

> Input:
> nums = [1, -1, 5, -2, 3], k = 3

> Output:
> 4

> Explanation:
> Subarray [1, -1, 5, -2] has sum = 3 and length 4 — the longest.
> 
> **Key insight:** Use prefix sums. If prefixSum[j] - prefixSum[i] = k, then subarray (i,j] has sum k. Store FIRST occurrence of each prefix sum in a map. Check if (currentSum - k) was seen before.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Entire array sums to k:** Length = n
2. **No subarray sums to k:** Return 0
3. **Negative numbers:** Sliding window doesn't work — need prefix sums
4. **k = 0:** Find longest subarray summing to 0
5. **Single element equals k:** Length = 1

<br>

---

## Solution 1: Brute Force — Check All Subarrays

### Time Complexity: O(N²)
**Why?**
- O(N²) subarrays, each sum can be computed incrementally in O(1)

**Detailed breakdown:**
- N = 100,000 → ~5,000,000,000 — TLE

### Space Complexity: O(1)

> **Drawback:**
> Checking all O(N²) subarrays. We can't use sliding window because negative numbers break the monotonic sum property (shrinking doesn't guarantee sum decreases).

> **Key Insight for Improvement:**
> Use prefix sums with a hash map. prefixSum[j] - prefixSum[i] = k means subarray (i,j] sums to k. Store the FIRST occurrence of each prefix sum. For maximum length, we want the earliest i where prefixSum[i] = currentSum - k.

<br>

---

## Solution 2: Prefix Sum + Hash Map (Optimal)

**Intuition:**
Running prefix sum. At each position j, check if (prefixSum - k) was seen at some earlier index i. If yes, subarray (i, j] has sum k and length j - i. Store first occurrence for maximum length.

**Algorithm:**
1. prefixSum = 0, maxLen = 0, map = {0: -1} (sum 0 at index -1)
2. For each j:
   - prefixSum += nums[j]
   - If (prefixSum - k) in map → maxLen = max(maxLen, j - map[prefixSum - k])
   - If prefixSum not in map → map[prefixSum] = j (store FIRST occurrence only)
3. Return maxLen

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Map operations: O(1) each

**Detailed breakdown:**
- N = 100,000 → 100,000 operations

**Example walkthrough:**
```
nums = [1, -1, 5, -2, 3], k = 3
map = {0: -1}

j=0: prefix=1, check 1-3=-2 not in map, map={0:-1, 1:0}
j=1: prefix=0, check 0-3=-3 not in map, 0 already in map → skip
j=2: prefix=5, check 5-3=2 not in map, map={0:-1, 1:0, 5:2}
j=3: prefix=3, check 3-3=0 in map at -1 → len=3-(-1)=4 ★
     map={0:-1, 1:0, 5:2, 3:3}
j=4: prefix=6, check 6-3=3 in map at 3 → len=4-3=1 (not better)

maxLen = 4 ✓
```

**Why store first occurrence only?**
- For LONGEST subarray, we want the earliest start index
- Later occurrences of the same prefix sum give shorter subarrays

### Space Complexity: O(N)
**Why?**
- Map stores at most N prefix sum entries

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Check all subarrays |
| Prefix Sum + Map | O(N) | O(N) | Hash map lookup for complement |

**Recommended Solution:** Prefix Sum + Hash Map (Solution 2) — O(N) time.

**Key Insights:**
1. **Can't use sliding window:** Negative numbers break monotonic property
2. **Prefix sum trick:** prefixSum[j] - prefixSum[i] = k → subarray sum = k
3. **First occurrence:** Store earliest index for each prefix sum → maximizes length
4. **Initialize map[0] = -1:** Handles subarrays starting from index 0


<br>
<br>

---

```code```
