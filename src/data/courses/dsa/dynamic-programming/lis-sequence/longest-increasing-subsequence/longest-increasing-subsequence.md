# Longest Increasing Subsequence

## Problem Statement

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**
```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
```

Explanation:
> The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

**Example 2:**
```
Input: nums = [0,1,0,3,2,3]
Output: 4
```

Explanation:
> The longest increasing subsequence is [0,1,2,3].

**Example 3:**
```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

<br>


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Values fit in 32-bit integer`
- `DP state space fits in memory`

<br>

---

## All Possible Edge Cases

1. **n = 0 or empty input:** Base case — return 0 or empty
2. **n = 1:** Single element — trivial case
3. **All same elements:** Check if pattern still applies
4. **Maximum constraints:** Verify time complexity handles worst case
5. **Negative values (if applicable):** Affects min/max DP transitions
6. **Result requires modular arithmetic:** Use MOD = 10⁹ + 7 to prevent overflow

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At each index, we have two choices: include current element in LIS (if it's greater than previous) or skip it. Try all possibilities and return maximum length.

**Recurrence Relation:**
```
f(i, prev) = 0                                    if i = N
f(i, prev) = max(1 + f(i+1, i), f(i+1, prev))   if nums[i] > nums[prev]
f(i, prev) = f(i+1, prev)                        otherwise
```

**Algorithm:**
1. Base case: If reached end, return 0
2. If current > previous, try taking it: 1 + solve(i+1, i)
3. Always try skipping: solve(i+1, prev)
4. Return maximum of both choices

### Time Complexity: O(2^N)
**Why exponential?**
- At each index, we make 2 recursive calls (take or skip)
- Maximum depth = N (array length)
- Total nodes in tree ≈ 2^N
- Example: N=10 → 2^10 = 1,024 calls

**Detailed breakdown:**
- Each state (i, prev) computed multiple times
- f(5, 3) might be called from multiple paths
- Overlapping subproblems cause exponential redundancy
- No memoization = recompute same states repeatedly

### Space Complexity: O(N)
**Why?**
- Recursion stack depth = N (maximum calls)
- No additional data structures
- Maximum N recursive calls active simultaneously

**Problem:** Too slow for arrays longer than 20 elements.

> **Key Insight for Improvement:**
> We're solving the same (i, prev) states repeatedly. If we cache results in a memo table, we can reduce time from exponential to polynomial.

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Store result of each (i, prev) state in a memo table. Before computing, check if already solved. This eliminates redundant calculations.

**Recurrence Relation:**
```
Same as recursive, but:
if (i, prev) in memo: return memo[i, prev]
else: compute, store in memo, return
```

**Algorithm:**
1. Create 2D memo dictionary/array
2. Before computing f(i, prev), check memo
3. If found, return cached value
4. Else compute recursively, store result, return

### Time Complexity: O(N²)
**Why quadratic?**
- Total unique states = N × N (i can be 0 to N-1, prev can be -1 to N-1)
- Each state computed exactly once
- Subsequent lookups are O(1)
- Total work = N² × O(1) = O(N²)

**Detailed breakdown:**
- First call to f(i, prev): compute and cache → O(1) work
- All future calls to f(i, prev): return memo[i, prev] → O(1)
- Total states = N × N
- Total time = N² × O(1) = O(N²)

**Improvement:** From O(2^N) to O(N²)
- Example: N=20
- Recursive: 2^20 ≈ 1,048,576 operations
- Memoization: 20×20 = 400 operations

### Space Complexity: O(N²)
**Why?**
- Memo table: N×N entries → O(N²)
- Recursion stack: O(N) depth
- Total: O(N²) + O(N) = O(N²) (dominant term)

**Breakdown:**
- Memo storage: Each of N×N states needs one entry
- Stack space: Maximum N recursive calls active
- Since N² > N, space is O(N²)

> **Key Insight for Improvement:**
> Memoization works but uses recursion. Can we solve iteratively? Yes - tabulation builds solution bottom-up with a different state definition.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Define dp[i] = length of LIS ending at index i. For each position, check all previous positions and extend their LIS if current element is larger.

**DP State:**
```
dp[i] = length of longest increasing subsequence ending at index i
```

**Transition:**
```
dp[i] = 1 + max(dp[j]) for all j < i where nums[j] < nums[i]
dp[i] = 1 if no such j exists
```

**Algorithm:**
1. Create dp array of size N, initialize all to 1
2. For each i from 1 to N-1:
   - For each j from 0 to i-1:
     - If nums[j] < nums[i]: dp[i] = max(dp[i], dp[j] + 1)
3. Return max(dp)

### Time Complexity: O(N²)
**Why?**
- Nested loops: outer N iterations, inner up to N iterations
- Each comparison: O(1) work
- Total: N × N × O(1) = O(N²)

**Detailed breakdown:**
- Initialize array: O(N)
- Fill dp table: 1 + 2 + 3 + ... + N = N(N+1)/2 ≈ O(N²)
- Find maximum: O(N)
- Total: O(N) + O(N²) + O(N) = O(N²)

**Comparison with Memoization:**
- Same time complexity: O(N²)
- But no recursion overhead (no function call stack)
- Simpler state definition (1D instead of 2D)
- Iterative approach typically 2-3× faster in practice

### Space Complexity: O(N)
**Why?**
- DP array: N entries → O(N)
- No recursion stack (iterative)
- Total: O(N)

**Breakdown:**
- dp array: N space
- Auxiliary variables: O(1)
- Total: O(N)

> **Key Insight for Improvement:**
> Can we do better than O(N²)? Yes! Using binary search with a different approach, we can achieve O(N log N).

<br>

---

## Solution 4: Binary Search (Optimal)

**Intuition:**
Maintain array `sub` where sub[i] = smallest ending element of all increasing subsequences of length i+1. For each number, use binary search to find its position in sub.

**Algorithm:**
1. Create empty array sub
2. For each num in nums:
   - Binary search for position where num should be inserted
   - If position = len(sub): append num (extends longest LIS)
   - Else: replace sub[position] with num (better ending for that length)
3. Return len(sub)

**Key Insight:**
- sub is always sorted
- sub[i] represents smallest tail for LIS of length i+1
- Replacing elements doesn't change LIS length, just improves future possibilities

### Time Complexity: O(N log N)
**Why?**
- Outer loop: N iterations (one per element)
- Binary search: O(log N) per iteration
- Total: N × log N = O(N log N)

**Detailed breakdown:**
- Process each element: N iterations
- Binary search in sorted array: log N per element
- Insert/replace operation: O(1)
- Total: N × log N = O(N log N)

**Improvement:** From O(N²) to O(N log N)
- Example: N=10,000
- Tabulation: 10,000² = 100,000,000 operations
- Binary Search: 10,000 × log(10,000) ≈ 133,000 operations (750× faster!)

### Space Complexity: O(N)
**Why?**
- sub array: at most N elements → O(N)
- Few variables: O(1)
- Total: O(N)

**Breakdown:**
- sub array: worst case N elements (all increasing)
- Binary search variables: O(1)
- Total: O(N)

**Why this works:**
- sub maintains smallest possible tails for each length
- When we see a number, we find where it fits
- If it extends current longest, we append
- If it's smaller than some tail, we replace (improves future options)
- Length of sub = length of LIS

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^N) | O(N) | Baseline - too slow |
| Memoization | O(N²) | O(N²) | Cache results - exponential to polynomial |
| Tabulation | O(N²) | O(N) | Simpler state - 1D DP |
| Binary Search | O(N log N) | O(N) | Optimal - maintain sorted subsequence |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Different state definition → simpler, less space
3. **Tabulation → Binary Search:** Maintain invariant → logarithmic search

**When to use each:**
- **Memoization:** Natural recursion, easier to implement
- **Tabulation:** Want iterative solution, O(N²) acceptable
- **Binary Search:** Need optimal O(N log N), most efficient

> **Final Complexity:** O(N log N) time, O(N) space

<br>
<br>

---

```code```
