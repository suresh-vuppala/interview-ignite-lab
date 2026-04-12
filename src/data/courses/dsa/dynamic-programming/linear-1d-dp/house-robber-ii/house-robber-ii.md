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

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: max(rob(nums[0..n-2]), rob(nums[1..n-1]))

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
