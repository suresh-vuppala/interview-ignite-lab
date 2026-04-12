Count ways to reach step N if you can take 1, 2, or 3 steps at a time.

<br>

> Input: n=4
> Output: 7 (1111,112,121,211,13,31,22)
> **Key insight:** dp[i] = dp[i-1] + dp[i-2] + dp[i-3]. Extension of climbing stairs with 3 step options.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(3^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

<br>

---

## Solution 2: DP — Bottom-up with three variables

**Recurrence:** `dp[i] = dp[i-1] + dp[i-2] + dp[i-3]`

**Algorithm:** Bottom-up with three variables

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
dp[0]=1, dp[1]=1, dp[2]=2, dp[3]=4, dp[4]=7
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(3^N) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N) | O(N) | Cache computed states |
| Tabulation | O(N) | O(1) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array


<br><br>

---

```code```
