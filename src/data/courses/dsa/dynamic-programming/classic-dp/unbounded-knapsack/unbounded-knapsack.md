Unbounded Knapsack: same as 0/1 but each item can be used unlimited times.

<br>

> **Key insight:** Process weights LEFT to RIGHT (allows reuse). dp[w] = max(dp[w], dp[w-wt[i]] + val[i]).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[w] = max(dp[w], dp[w-wt[i]] + val[i]) — LEFT to RIGHT`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[w] = max(dp[w], dp[w-wt[i]] + val[i]) — LEFT to RIGHT`

### Time Complexity: O(N×W)
**Why?** Each state computed once.

### Space Complexity: O(W)

**Example walkthrough:**
```
Same as 0/1 but iterate LEFT to RIGHT to allow repeated items
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N×W) | O(W) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible
3. **Key difference from 0/1:** Direction of inner loop. Left-to-right = reuse allowed

<br><br>

---

```code```
