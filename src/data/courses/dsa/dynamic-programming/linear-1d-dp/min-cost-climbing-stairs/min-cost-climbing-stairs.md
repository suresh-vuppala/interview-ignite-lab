Each step has a cost. Pay the cost to climb 1 or 2 steps from that position. Find minimum cost to reach the top.

<br>

> Input: cost=[10,15,20]
> Output: 15 (start at index 1, pay 15, climb 2 to top)
> **Key insight:** dp[i] = cost[i] + min(dp[i-1], dp[i-2]). Choose cheaper path to reach step i, then pay its cost.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = cost[i] + min(dp[i-1], dp[i-2])

<br>

---

## Solution 2: DP — Bottom-up with two variables

**Recurrence:** `dp[i] = cost[i] + min(dp[i-1], dp[i-2])`

**Algorithm:** Bottom-up with two variables

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
cost=[10,15,20]: dp[0]=10, dp[1]=15, dp[2]=20+min(10,15)=30. Answer=min(dp[1],dp[2])=min(15,30)=15
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
