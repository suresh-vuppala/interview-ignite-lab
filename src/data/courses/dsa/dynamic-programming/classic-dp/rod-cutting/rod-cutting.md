Given a rod of length N and prices for each length 1..N, maximize revenue by cutting into pieces.

<br>

> **Key insight:** Unbounded knapsack: dp[len] = max(dp[len], price[i] + dp[len-i]) for each piece length i.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[l] = max(price[i] + dp[l-i]) for i=1..l`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[l] = max(price[i] + dp[l-i]) for i=1..l`

### Time Complexity: O(N²)
**Why?** Each state computed once.

### Space Complexity: O(N)

**Example walkthrough:**
```
prices=[1,5,8,9,10,17,17,20], N=8 → cut into 2+6=5+17=22
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N²) | O(N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
