Given K eggs and N floors, find minimum number of trials to find the critical floor.

<br>

> **Key insight:** dp[k][n] = 1 + min(max(dp[k-1][i-1], dp[k][n-i])) for i=1..n. Binary search optimization possible.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[k][n] = 1 + min over i of max(dp[k-1][i-1], dp[k][n-i])`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[k][n] = 1 + min over i of max(dp[k-1][i-1], dp[k][n-i])`

### Time Complexity: O(K×N×logN) with binary search
**Why?** Each state computed once.

### Space Complexity: O(K×N)

**Example walkthrough:**
```
K=2, N=10 → 4 trials. Optimal strategy: drop from floors 4, 7, 9, 10
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(K×N×logN) with binary search | O(K×N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible
3. **Binary search optimization:** For fixed k, the break/nobreak functions are monotonic → binary search for optimal floor

<br><br>

---

```code```
