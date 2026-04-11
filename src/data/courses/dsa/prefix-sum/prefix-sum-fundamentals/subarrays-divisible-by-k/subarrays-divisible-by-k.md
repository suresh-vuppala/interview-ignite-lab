Given an integer array and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

<br>

> Input:
> nums = [4, 5, 0, -2, -3, 1], k = 5

> Output:
> 7

> Explanation:
> Subarrays with sum divisible by 5:
> [4, 5, 0, -2, -3, 1] (sum = 5), [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
> 
> **Key insight:** Use prefix sum modulo k. If two prefix sums have same remainder, the subarray between them is divisible by k.

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
Generate all possible subarrays, calculate their sum, and check if divisible by k.

**Algorithm:**
1. Initialize count = 0
2. For each starting index i (0 to n-1):
   - For each ending index j (i to n-1):
     - Calculate sum of subarray [i...j]
     - If sum % k == 0, increment count
3. Return count

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
- Only storing count and loop variables
- No extra data structures

> **Key Insight for Improvement:**
> We're recalculating sum from scratch for each subarray. Can we reuse previous sum? Yes! When extending from [i...j] to [i...j+1], just add nums[j+1].

<br>

---

## Solution 2: Brute Force Optimized

**Intuition:**
For each starting position, maintain a running sum as we extend the subarray. This avoids recalculating the entire sum.

**Algorithm:**
1. Initialize count = 0
2. For each starting index i:
   - Initialize currentSum = 0
   - For each ending index j from i to n-1:
     - Add nums[j] to currentSum
     - If currentSum % k == 0, increment count
3. Return count

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: N iterations
- Sum update and modulo: O(1)
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
- Only currentSum and count variables
- No extra space

> **Key Insight for Improvement:**
> We're still checking all subarrays. Can we use prefix sum property? Yes! If prefixSum[j] % k == prefixSum[i] % k, then subarray [i+1...j] is divisible by k.

<br>

---

## Solution 3: Prefix Sum with HashMap

**Intuition:**
Use prefix sum modulo k. Store frequency of each remainder in a HashMap. If we see the same remainder again, all previous occurrences form valid subarrays with current position.

**Key Property:**
```
If (prefixSum[j] - prefixSum[i]) % k == 0
Then prefixSum[j] % k == prefixSum[i] % k
```

**Algorithm:**
1. Create HashMap to store remainder → frequency
2. Initialize prefixSum = 0, count = 0
3. Add remainder 0 with frequency 1 (empty prefix)
4. For each element:
   - Add element to prefixSum
   - Calculate remainder = prefixSum % k
   - Handle negative remainders: remainder = (remainder + k) % k
   - Add map[remainder] to count (all previous same remainders)
   - Increment map[remainder]
5. Return count

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

### Space Complexity: O(K)
**Why?**
- HashMap stores at most K different remainders (0 to k-1)
- O(K) space

**Why this works:**
- If two prefix sums have same remainder mod k, their difference is divisible by k
- HashMap counts how many times each remainder appeared
- Each previous occurrence forms a valid subarray with current position

**Handling negative remainders:**
- In many languages, -1 % 5 = -1 (not 4)
- Fix: remainder = (remainder % k + k) % k
- This ensures remainder is always in range [0, k-1]

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N³) | O(1) | Baseline - check all subarrays |
| Brute Optimized | O(N²) | O(1) | Running sum - avoid recalc |
| Prefix Sum + HashMap | O(N) | O(K) | Count remainders - use modulo property |

**Recommended Solution:** Prefix Sum with HashMap (Solution 3) - O(N) time, O(K) space.

**Key Insights:**
1. **Brute → Optimized:** Running sum → avoid recalculation
2. **Optimized → Prefix Sum:** Modulo property → if same remainder, difference divisible by k
3. **HashMap usage:** Count frequency of remainders → each match forms valid subarray

<br>
<br>

---

```code```
