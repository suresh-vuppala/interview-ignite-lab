Given an array of integers and a target sum k, find the length of the longest subarray with sum equal to k.

<br>

> Input:
> nums = [1, -1, 5, -2, 3], k = 3

> Output:
> 4

> Explanation:
> The longest subarray with sum = 3 is [1, -1, 5, -2] with length 4.
> Other subarrays: [3] (length 1), [-2, 5] (length 2)
> 
> **Key insight:** Use prefix sum with HashMap. Store first occurrence of each prefix sum to maximize subarray length.

<br>


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁵ ≤ nums[i] ≤ 10⁵`
- `Prefix sum may overflow — use long/long long if needed`

<br>

---

## All Possible Edge Cases

1. **Single element:** Subarray is the element itself
2. **All zeros:** All prefix sums are 0
3. **All same values:** Uniform prefix sum growth
4. **Negative values:** Prefix sum can decrease
5. **Target = 0:** Count subarrays summing to 0 (common trick)
6. **Entire array is the answer:** Sum of all elements matches target

<br>

---

## Solution 1: Brute Force

**Intuition:**
Generate all possible subarrays, calculate their sum, and track the maximum length where sum equals k.

**Algorithm:**
1. Initialize maxLen = 0
2. For each starting index i (0 to n-1):
   - For each ending index j (i to n-1):
     - Calculate sum of subarray [i...j]
     - If sum == k, update maxLen with (j - i + 1)
3. Return maxLen

### Time Complexity: O(N³)
**Why?**
- Outer loop: N iterations (starting positions)
- Inner loop: N iterations (ending positions)
- Sum calculation: O(N) for each subarray
- Total: N × N × N = O(N³)

**Detailed breakdown:**
- Total subarrays: N×(N+1)/2 ≈ N²/2
- Each subarray sum: O(N) to calculate
- Total: N²/2 × N = O(N³)
- Example: Array size 100 → 1,000,000 operations

### Space Complexity: O(1)
**Why?**
- Only storing maxLen and loop variables
- No extra data structures

> **Key Insight for Improvement:**
> We're recalculating sum from scratch for each subarray. Can we reuse previous sum? Yes! When extending from [i...j] to [i...j+1], just add nums[j+1].

<br>

---

## Solution 2: Brute Force Optimized

**Intuition:**
For each starting position, maintain a running sum as we extend the subarray. This avoids recalculating the entire sum.

**Algorithm:**
1. Initialize maxLen = 0
2. For each starting index i:
   - Initialize currentSum = 0
   - For each ending index j from i to n-1:
     - Add nums[j] to currentSum
     - If currentSum == k, update maxLen with (j - i + 1)
3. Return maxLen

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: N iterations
- Sum update: O(1)
- Total: N × N = O(N²)

**Detailed breakdown:**
- For each starting position: extend to all ending positions
- Total: N + (N-1) + ... + 1 = N×(N+1)/2 ≈ O(N²)
- Example: Array size 1000 → 500,500 operations

**Improvement:** From O(N³) to O(N²)
- Example: Array size 100
- Brute force: 1,000,000 operations
- Optimized: 5,050 operations (200× faster!)

### Space Complexity: O(1)
**Why?**
- Only currentSum and maxLen variables
- No extra space

> **Key Insight for Improvement:**
> We're still checking all subarrays. Can we use prefix sum property? Yes! If prefixSum[j] - prefixSum[i] = k, then subarray [i+1...j] has sum k.

<br>

---

## Solution 3: Prefix Sum with HashMap

**Intuition:**
Use prefix sum with HashMap. For each position, check if (prefixSum - k) exists in the map. If yes, we found a subarray with sum k. Store first occurrence of each prefix sum to maximize length.

**Key Property:**
```
If prefixSum[j] - prefixSum[i] = k
Then prefixSum[i] = prefixSum[j] - k
```

**Algorithm:**
1. Create HashMap to store prefixSum → first index
2. Initialize prefixSum = 0, maxLen = 0
3. Add 0 → -1 to map (empty prefix before index 0)
4. For each index i:
   - Add nums[i] to prefixSum
   - If (prefixSum - k) in map:
     - Calculate length = i - map[prefixSum - k]
     - Update maxLen
   - If prefixSum not in map, store it with index i
5. Return maxLen

### Time Complexity: O(N)
**Why?**
- Single pass through array: N iterations
- HashMap operations (get/put): O(1) average
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- One loop: N iterations
- Each iteration: O(1) operations
- Total: N operations
- Example: Array size 1000 → 1000 operations

**Improvement:** From O(N²) to O(N)
- Example: Array size 1000
- Previous: 500,500 operations
- Current: 1000 operations (500× faster!)

### Space Complexity: O(N)
**Why?**
- HashMap stores at most N different prefix sums
- O(N) space

**Why store first occurrence only?**
- We want maximum length
- If prefixSum appears at indices i and j (i < j), using i gives longer subarray
- So we only store first occurrence

**Why add 0 → -1?**
- Handles case where subarray starts from index 0
- If prefixSum[j] = k, then subarray [0...j] has sum k
- Length = j - (-1) = j + 1 ✓

<br>

---

## Solution 4: Sliding Window (Positive Integers Only)

**Intuition:**
For arrays with only positive integers, use sliding window. Expand right to increase sum, shrink left when sum > k.

**Algorithm:**
1. Initialize left = 0, currentSum = 0, maxLen = 0
2. For right from 0 to n-1:
   - Add nums[right] to currentSum
   - While currentSum > k and left <= right:
     - Subtract nums[left] from currentSum
     - Increment left
   - If currentSum == k, update maxLen
3. Return maxLen

### Time Complexity: O(N)
**Why?**
- Right pointer: N moves
- Left pointer: at most N moves
- Each element visited at most twice
- Total: 2N = O(N)

### Space Complexity: O(1)
**Why?**
- Only pointer variables
- No extra data structures

**Limitation:** Only works for positive integers. For arrays with negatives or zeros, use Solution 3.

**Why doesn't work with negatives?**
- With negatives, removing from left might increase sum
- Sliding window assumes monotonic property (adding increases, removing decreases)
- This breaks with negative numbers

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Works with Negatives | Key Feature |
|----------|------|-------|---------------------|-------------|
| Brute Force | O(N³) | O(1) | Yes | Check all subarrays |
| Brute Optimized | O(N²) | O(1) | Yes | Running sum - avoid recalc |
| Prefix Sum + HashMap | O(N) | O(N) | Yes | Store first occurrence - maximize length |
| Sliding Window | O(N) | O(1) | No | Only for positive integers |

**Recommended Solution:**
- **With negatives/zeros:** Prefix Sum + HashMap (Solution 3) - O(N) time, O(N) space
- **Only positive integers:** Sliding Window (Solution 4) - O(N) time, O(1) space

**Key Insights:**
1. **Brute → Optimized:** Running sum → avoid recalculation
2. **Optimized → Prefix Sum:** If prefixSum[j] - prefixSum[i] = k, subarray [i+1...j] has sum k
3. **Store first occurrence:** Maximize subarray length
4. **Sliding window limitation:** Doesn't work with negatives (non-monotonic)

<br>
<br>

---

```code```
