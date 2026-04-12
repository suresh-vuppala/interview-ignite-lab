N posts, K colors. No more than 2 consecutive posts same color. Count ways.

<br>

> Input: n=3, k=2
> Output: 6
> **Key insight:** dp[i] = (k-1) * (dp[i-1] + dp[i-2]). Same as prev: k-1 choices. Different from prev: k-1 choices for each of dp[i-2] arrangements.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(K^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = (k-1) * (dp[i-1] + dp[i-2])

<br>

---

## Solution 2: DP — Bottom-up with two variables

**Recurrence:** `dp[i] = (k-1) * (dp[i-1] + dp[i-2])`

**Algorithm:** Bottom-up with two variables

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
k=2: dp[1]=2, dp[2]=4, dp[3]=1*(4+2)=6
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(K^N) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N) | O(N) | Cache computed states |
| Tabulation | O(N) | O(1) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array


<br><br>

---

```code```
