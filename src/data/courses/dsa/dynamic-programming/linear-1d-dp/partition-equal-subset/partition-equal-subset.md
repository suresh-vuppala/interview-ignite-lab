Can you partition an array into two subsets with equal sum?

<br>

> Input: nums=[1,5,11,5]
> Output: true (subsets {1,5,5} and {11})
> **Key insight:** If total sum is odd → false. Target = sum/2. Reduce to: does a subset sum to target? 0/1 Knapsack variant with boolean DP.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[j] = dp[j] || dp[j - nums[i]]

<br>

---

## Solution 2: DP — 1D boolean DP array (space-optimized knapsack)

**Recurrence:** `dp[j] = dp[j] || dp[j - nums[i]]`

**Algorithm:** 1D boolean DP array (space-optimized knapsack)

### Time Complexity: O(N × sum)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(sum)

**Example walkthrough:**
```
nums=[1,5,11,5], sum=22, target=11
Process each num, update dp[j] = dp[j] || dp[j-num]
After all: dp[11] = true ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^N) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N × sum) | O(N) | Cache computed states |
| Tabulation | O(N × sum) | O(sum) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array


<br><br>

---

```code```
