Break a positive integer n into at least two positive integers that sum to n. Maximize the product.

<br>

> Input: n=10
> Output: 36 (3+3+4=10, 3×3×4=36)
> **Key insight:** dp[i] = max over j of (j × max(i-j, dp[i-j])). For each split j, either use (i-j) directly or break it further.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(N²)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = max(j * max(i-j, dp[i-j])) for j=1..i-1

<br>

---

## Solution 2: DP — Bottom-up DP

**Recurrence:** `dp[i] = max(j * max(i-j, dp[i-j])) for j=1..i-1`

**Algorithm:** Bottom-up DP

### Time Complexity: O(N²)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(N)

**Example walkthrough:**
```
dp[2]=1, dp[3]=2, dp[4]=4, dp[5]=6, dp[6]=9, dp[7]=12, dp[8]=18, dp[9]=27, dp[10]=36
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(N²) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N²) | O(N) | Cache computed states |
| Tabulation | O(N²) | O(N) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array
4. **Math insight:** Always break into 3s (except remainder 1→use 4, remainder 2→keep 2)

<br><br>

---

```code```
