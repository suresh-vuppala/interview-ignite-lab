Tile a 2×N board using dominoes (1×2) and trominoes (L-shaped). Count ways mod 10^9+7.

<br>

> Input: n=3
> Output: 5
> **Key insight:** dp[i] = 2*dp[i-1] + dp[i-3]. Two full columns can be filled by extending previous patterns. The dp[i-3] accounts for the L-shaped tromino combinations.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = 2*dp[i-1] + dp[i-3]

<br>

---

## Solution 2: DP — Bottom-up with recurrence

**Recurrence:** `dp[i] = 2*dp[i-1] + dp[i-3]`

**Algorithm:** Bottom-up with recurrence

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
dp[1]=1, dp[2]=2, dp[3]=5, dp[4]=11, dp[5]=24
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
