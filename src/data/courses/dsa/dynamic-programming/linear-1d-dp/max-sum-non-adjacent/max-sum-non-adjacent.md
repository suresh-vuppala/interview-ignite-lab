Find maximum sum of non-adjacent elements in an array. Same as House Robber.

<br>

> Input: nums=[3,2,7,10]
> Output: 13 (pick 3+10=13)
> **Key insight:** Same as House Robber: dp[i] = max(dp[i-1], dp[i-2] + nums[i]).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = max(dp[i-1], dp[i-2] + nums[i])

<br>

---

## Solution 2: DP — Bottom-up with two variables

**Recurrence:** `dp[i] = max(dp[i-1], dp[i-2] + nums[i])`

**Algorithm:** Bottom-up with two variables

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
nums=[3,2,7,10]: dp[0]=3, dp[1]=3, dp[2]=max(3,3+7)=10, dp[3]=max(10,3+10)=13
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
