Find the contiguous subarray with the largest sum.

<br>

> Input: nums=[-2,1,-3,4,-1,2,1,-5,4]
> Output: 6 (subarray [4,-1,2,1])
> **Key insight:** Kadane's algorithm: dp[i] = max(nums[i], dp[i-1] + nums[i]). Either start new subarray at i, or extend the previous one.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

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
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: DP — Kadane's — single variable tracking current sum

**Recurrence:** `dp[i] = max(nums[i], dp[i-1] + nums[i])`

**Algorithm:** Kadane's — single variable tracking current sum

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
nums=[-2,1,-3,4,-1,2,1,-5,4]
curr: -2,1,-2,4,3,5,6,1,5
max:  -2,1,1,4,4,5,6,6,6 → Answer=6
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(N²) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N) | O(N) | Cache computed states |
| Tabulation | O(N) | O(1) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array
4. **Kadane's = DP:** currentSum = max(nums[i], currentSum + nums[i])
5. **FAANG top-10:** Most frequently asked DP problem

<br><br>

---

```code```
