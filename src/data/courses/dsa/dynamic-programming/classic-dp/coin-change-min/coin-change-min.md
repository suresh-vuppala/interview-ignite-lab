Find minimum number of coins to make amount. Unlimited supply of each coin.

<br>

> **Key insight:** dp[amount] = min(dp[amount], dp[amount-coin]+1). Try each coin, take the one giving fewest total coins.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[i] = min(dp[i-coin] + 1) for each coin`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[i] = min(dp[i-coin] + 1) for each coin`

### Time Complexity: O(amount × coins)
**Why?** Each state computed once.

### Space Complexity: O(amount)

**Example walkthrough:**
```
coins=[1,5,11], amount=15 → dp[15]=3 (5+5+5)
Greedy would pick 11+1+1+1+1=5 coins — WRONG! DP finds optimal.
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(amount × coins) | O(amount) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible
3. **Greedy fails:** coins=[1,5,11], amount=15. Greedy=5, DP=3
4. **FAANG classic:** Tests unbounded knapsack understanding

<br><br>

---

```code```
