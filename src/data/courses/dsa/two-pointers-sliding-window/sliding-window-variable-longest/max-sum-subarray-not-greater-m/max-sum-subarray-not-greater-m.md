Given an array of positive integers and a target value M, find the maximum sum of a subarray such that the sum is as large as possible but not greater than M.

<br>

> Input:
> arr = [2, 3, 1, 5, 4], M = 7

> Output:
> 7

> Explanation:
> Subarray [3, 1] has sum 4
> Subarray [2, 3, 1] has sum 6
> Subarray [3, 4] has sum 7 ← Maximum sum ≤ 7
> Subarray [1, 5] has sum 6
> 
> **Key insight:** Use sliding window for positive integers, or prefix sum + binary search for arrays with negatives.

<br>

---

## Solution 1: Brute Force

**Intuition:**
Generate all possible subarrays, calculate their sums, and track the maximum sum that doesn't exceed M.

**Algorithm:**
1. Initialize maxSum = 0
2. For each starting index i (0 to n-1):
   - For each ending index j (i to n-1):
     - Calculate sum of subarray [i...j]
     - If sum <= M, update maxSum
3. Return maxSum

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
- Only storing maxSum and loop variables
- No extra data structures

> **Key Insight for Improvement:**
> We're recalculating sum from scratch for each subarray. Can we reuse previous sum? Yes! When extending from [i...j] to [i...j+1], just add arr[j+1].

<br>

---

## Solution 2: Brute Force Optimized

**Intuition:**
For each starting position, maintain a running sum as we extend the subarray. This avoids recalculating the entire sum.

**Algorithm:**
1. Initialize maxSum = 0
2. For each starting index i:
   - Initialize currentSum = 0
   - For each ending index j from i to n-1:
     - Add arr[j] to currentSum
     - If currentSum <= M, update maxSum
     - If currentSum > M, break (for positive integers only)
3. Return maxSum

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: at most N iterations
- Sum update: O(1)
- Total: N × N = O(N²)

**Detailed breakdown:**
- For each starting position: extend until sum > M
- Worst case: all subarrays valid
- Total: N + (N-1) + ... + 1 = N×(N+1)/2 ≈ O(N²)
- Example: Array size 1000 → 500,500 operations

**Improvement:** From O(N³) to O(N²)
- Example: Array size 100
- Brute force: 1,000,000 operations
- Optimized: 5,050 operations (200× faster!)

### Space Complexity: O(1)
**Why?**
- Only currentSum and maxSum variables
- No extra space

> **Key Insight for Improvement:**
> For positive integers, we can use sliding window. When sum > M, shrink from left. This gives O(N) time.

<br>

---

## Solution 3: Sliding Window (Positive Integers Only)

**Intuition:**
Use two pointers to maintain a window. Expand right to increase sum. When sum > M, shrink from left. Track maximum valid sum.

**Algorithm:**
1. Initialize left = 0, currentSum = 0, maxSum = 0
2. For right from 0 to n-1:
   - Add arr[right] to currentSum
   - While currentSum > M:
     - Subtract arr[left] from currentSum
     - Increment left
   - Update maxSum with currentSum
3. Return maxSum

### Time Complexity: O(N)
**Why?**
- Right pointer: moves from 0 to n-1 → N moves
- Left pointer: moves from 0 to n-1 → at most N moves
- Each element visited at most twice
- Total: 2N = O(N)

**Detailed breakdown:**
- Right pointer: N iterations
- Left pointer: at most N moves total (never goes backward)
- Each element added once, removed at most once
- Total: 2N operations
- Example: Array size 1000 → 2000 operations

**Improvement:** From O(N²) to O(N)
- Example: Array size 1000
- Previous: 500,500 operations
- Current: 2000 operations (250× faster!)

### Space Complexity: O(1)
**Why?**
- Only pointer variables and sum trackers
- No extra data structures

**Limitation:** Only works for positive integers. For arrays with negatives, use Solution 4.

> **Key Insight for Improvement:**
> For arrays with negative numbers, sliding window doesn't work (removing from left might increase sum). Use prefix sum + binary search or TreeSet.

<br>

---

## Solution 4: Prefix Sum + Binary Search (Works with Negatives)

**Intuition:**
Calculate prefix sums. For each position i, use binary search to find the largest j where prefixSum[j] - prefixSum[i] <= M. Use TreeSet to maintain sorted prefix sums.

**Algorithm:**
1. Create TreeSet to store prefix sums
2. Initialize prefixSum = 0, maxSum = 0
3. Add 0 to TreeSet
4. For each element:
   - Add element to prefixSum
   - Find smallest prefix >= (prefixSum - M) using binary search
   - If found, update maxSum
   - Add prefixSum to TreeSet
5. Return maxSum

### Time Complexity: O(N log N)
**Why?**
- Loop through array: N iterations
- TreeSet operations (add/ceiling): O(log N) per iteration
- Total: N × log N

**Detailed breakdown:**
- For each of N elements:
  - TreeSet ceiling: O(log N)
  - TreeSet add: O(log N)
- Total: N × 2 log N = O(N log N)
- Example: Array size 1000 → 1000 × 10 = 10,000 operations

**Comparison:**
- Slower than sliding window O(N) for positive integers
- But works for arrays with negative numbers
- More versatile solution

### Space Complexity: O(N)
**Why?**
- TreeSet stores N prefix sums
- O(N) space

**Why this works:**
- Prefix sum allows O(1) range sum calculation
- TreeSet maintains sorted order for binary search
- Works for any array (positive, negative, mixed)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Works with Negatives | Key Feature |
|----------|------|-------|---------------------|-------------|
| Brute Force | O(N³) | O(1) | Yes | Check all subarrays |
| Brute Optimized | O(N²) | O(1) | Yes | Running sum - avoid recalc |
| Sliding Window | O(N) | O(1) | No | Optimal for positive integers |
| Prefix + Binary Search | O(N log N) | O(N) | Yes | Works for any array |

**Recommended Solution:**
- **Positive integers only:** Sliding Window (Solution 3) - O(N) time, O(1) space
- **With negative numbers:** Prefix Sum + Binary Search (Solution 4) - O(N log N) time, O(N) space

**Key Insights:**
1. **Brute → Optimized:** Running sum → avoid recalculation
2. **Optimized → Sliding Window:** Two pointers → linear time for positive integers
3. **Sliding Window limitation:** Doesn't work with negatives (removing left might increase sum)
4. **Prefix Sum solution:** Universal approach for any array type


<br>
<br>

---

```code```
