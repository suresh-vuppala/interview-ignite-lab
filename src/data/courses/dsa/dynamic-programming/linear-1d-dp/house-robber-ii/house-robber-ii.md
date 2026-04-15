Houses in a CIRCLE. First and last are adjacent. Can't rob adjacent. Maximize total.

<br>

> Input: nums=[2,3,2]
> Output: 3 (rob house 1 only — can't rob both 0 and 2 since they're adjacent in circle)
> **Key insight:** Circular constraint: can't rob both first and last. Run House Robber twice: once excluding first house, once excluding last. Take max.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **Single house:** rob it
2. **Two houses:** max of both
3. **All same values in circle**
4. **N = 3:** pick max of three options

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

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: DP — Two passes of House Robber I

**Recurrence:** `max(rob(nums[0..n-2]), rob(nums[1..n-1]))`

**Algorithm:** Two passes of House Robber I

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
nums=[2,3,2]: rob([2,3])=3, rob([3,2])=3. Answer=max(3,3)=3
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^N) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N) | O(N) | Cache computed states |
| Tabulation | O(N) | O(1) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array


<br><br>

---

```code```
