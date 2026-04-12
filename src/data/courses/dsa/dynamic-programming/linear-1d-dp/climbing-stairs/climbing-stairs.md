You can climb 1 or 2 steps. How many distinct ways to reach the top of N steps?

<br>

> Input: n=3
> Output: 3 (1+1+1, 1+2, 2+1)
> **Key insight:** dp[i] = dp[i-1] + dp[i-2]. Same as Fibonacci! Either take 1 step from i-1 or 2 steps from i-2.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = dp[i-1] + dp[i-2]

<br>

---

## Solution 2: DP — Bottom-up with two variables

**Recurrence:** `dp[i] = dp[i-1] + dp[i-2]`

**Algorithm:** Bottom-up with two variables

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1) with space optimization

**Example walkthrough:**
```
n=5: dp[1]=1, dp[2]=2, dp[3]=3, dp[4]=5, dp[5]=8
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^N) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N) | O(N) | Cache computed states |
| Tabulation | O(N) | O(1) with space optimization | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array
4. **Fibonacci variant:** This IS Fibonacci with different base cases

<br><br>

---

```code```
