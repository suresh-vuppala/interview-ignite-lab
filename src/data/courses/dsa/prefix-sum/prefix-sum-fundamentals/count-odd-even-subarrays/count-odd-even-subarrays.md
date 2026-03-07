Given an array of integers, count the number of subarrays where the count of odd numbers equals the count of even numbers.

<br>

> Input:
> nums = [2, 5, 4, 6, 3, 1]

> Output:
> 6

> Explanation:
> Subarrays with equal odd and even counts:
> [2,5] (1 odd, 1 even), [5,4] (1 odd, 1 even), [4,6,3,1] (2 odd, 2 even),
> [2,5,4,6,3,1] (3 odd, 3 even), [5,4,6,3] (2 odd, 2 even), [6,3] (1 odd, 1 even)
> 
> **Key insight:** Transform problem: treat odd as +1, even as -1. Find subarrays with sum = 0.

<br>

---

## Solution 1: Brute Force

**Intuition:**
Generate all possible subarrays, count odd and even numbers in each, and check if counts are equal.

**Algorithm:**
1. Initialize count = 0
2. For each starting index i (0 to n-1):
   - For each ending index j (i to n-1):
     - Count odd and even numbers in subarray [i...j]
     - If oddCount == evenCount, increment count
3. Return count

### Time Complexity: O(N³)
**Why?**
- Outer loop: N iterations (starting positions)
- Inner loop: N iterations (ending positions)
- Counting odd/even: O(N) for each subarray
- Total: N × N × N = O(N³)

**Detailed breakdown:**
- Total subarrays: N×(N+1)/2 ≈ N²/2
- Each subarray: O(N) to count odd/even
- Total: N²/2 × N = O(N³)
- Example: Array size 100 → 1,000,000 operations

### Space Complexity: O(1)
**Why?**
- Only storing count and loop variables
- No extra data structures

> **Key Insight for Improvement:**
> We're recounting from scratch for each subarray. Can we maintain counts incrementally? Yes! When extending from [i...j] to [i...j+1], just check if nums[j+1] is odd or even.

<br>

---

## Solution 2: Brute Force Optimized

**Intuition:**
For each starting position, maintain running counts of odd and even numbers as we extend the subarray.

**Algorithm:**
1. Initialize count = 0
2. For each starting index i:
   - Initialize oddCount = 0, evenCount = 0
   - For each ending index j from i to n-1:
     - If nums[j] is odd, increment oddCount
     - Else increment evenCount
     - If oddCount == evenCount, increment count
3. Return count

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: N iterations
- Odd/even check: O(1)
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
- Only count variables
- No extra space

> **Key Insight for Improvement:**
> Transform the problem! Treat odd as +1, even as -1. Then "equal odd/even counts" becomes "sum = 0". Use prefix sum with HashMap.

<br>

---

## Solution 3: Transform + Prefix Sum with HashMap

**Intuition:**
Transform array: odd → +1, even → -1. Now we need subarrays with sum = 0. Use prefix sum with HashMap to count such subarrays.

**Transformation:**
```
Original: [2, 5, 4, 6, 3, 1]
          (E, O, E, E, O, O)
Transform: [-1, +1, -1, -1, +1, +1]
```

**Key Property:**
```
If prefixSum[j] - prefixSum[i] = 0
Then prefixSum[j] = prefixSum[i]
```

**Algorithm:**
1. Create HashMap to store prefixSum → frequency
2. Initialize prefixSum = 0, count = 0
3. Add 0 with frequency 1 (empty prefix)
4. For each element:
   - If odd, add +1 to prefixSum
   - If even, add -1 to prefixSum
   - Add map[prefixSum] to count (all previous same prefix sums)
   - Increment map[prefixSum]
5. Return count

### Time Complexity: O(N)
**Why?**
- Single pass through array: N iterations
- HashMap operations (get/put): O(1) average
- Odd/even check: O(1)
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

**Why this works:**
- Equal odd/even counts means difference = 0
- Transform to +1/-1 makes this a "sum = 0" problem
- If two prefix sums are equal, subarray between them has sum 0
- HashMap counts frequency of each prefix sum

**Example walkthrough:**
```
nums = [2, 5, 4, 6, 3, 1]
transform = [-1, +1, -1, -1, +1, +1]
prefixSum = [0, -1, 0, -1, -2, -1, 0]
           ↑   ↑   ↑   ↑   ↑   ↑   ↑
map: {0:1} → {0:1,-1:1} → {0:2,-1:1} → {0:2,-1:2} → {0:2,-1:2,-2:1} → {0:2,-1:3,-2:1} → {0:3,-1:3,-2:1}

When prefixSum = 0 (3rd time): count += 2 (previous 2 occurrences)
When prefixSum = -1 (2nd time): count += 1
When prefixSum = -1 (3rd time): count += 2
When prefixSum = 0 (4th time): count += 3
Total: 2 + 1 + 2 + 1 = 6 ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N³) | O(1) | Baseline - count for each subarray |
| Brute Optimized | O(N²) | O(1) | Maintain counts - avoid recount |
| Transform + Prefix Sum | O(N) | O(N) | Transform to sum=0 problem - use HashMap |

**Recommended Solution:** Transform + Prefix Sum with HashMap (Solution 3) - O(N) time, O(N) space.

**Key Insights:**
1. **Brute → Optimized:** Maintain running counts → avoid recounting
2. **Optimized → Transform:** Equal counts → difference = 0 → transform to +1/-1
3. **Transform → Prefix Sum:** Sum = 0 problem → use prefix sum HashMap technique

<br>
<br>

---

```code```
