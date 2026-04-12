Fill a 2×N board with 1×2 tiles (horizontal or vertical). Count the number of ways.

<br>

> Input: n=4
> Output: 5
> **Key insight:** dp[i] = dp[i-1] + dp[i-2]. Place vertical tile (leaves 2×(n-1)) or two horizontal tiles (leaves 2×(n-2)). Same as Fibonacci!

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

## Solution 2: DP — Bottom-up Fibonacci

**Recurrence:** `dp[i] = dp[i-1] + dp[i-2]`

**Algorithm:** Bottom-up Fibonacci

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
dp[1]=1, dp[2]=2, dp[3]=3, dp[4]=5
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
