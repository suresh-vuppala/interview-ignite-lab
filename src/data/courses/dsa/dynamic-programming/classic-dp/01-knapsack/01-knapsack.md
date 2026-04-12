0/1 Knapsack: given N items with weights and values, maximize value within weight capacity W. Each item used at most once.

<br>

> **Key insight:** dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i]). Either skip item or take it.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i])`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i])`

### Time Complexity: O(N×W)
**Why?** Each state computed once.

### Space Complexity: O(W)

**Example walkthrough:**
```
items: wt=[1,3,4,5], val=[1,4,5,7], W=7 → dp[7]=9 (items 2+3: wt=3+4=7, val=4+5=9)
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
3. **Foundation:** Subset sum, partition, target sum are all knapsack variants
4. **1D optimization:** Process weights RIGHT to LEFT to avoid reusing items

<br><br>

---

```code```
