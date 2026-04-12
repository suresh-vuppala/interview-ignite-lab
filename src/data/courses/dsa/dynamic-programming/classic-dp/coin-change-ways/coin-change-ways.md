Count the number of ways to make amount using given coins (unlimited supply).

<br>

> **Key insight:** dp[amount] += dp[amount-coin]. For each coin, add the ways to make (amount-coin).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[a] += dp[a-coin] for each coin`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[a] += dp[a-coin] for each coin`

### Time Complexity: O(amount × coins)
**Why?** Each state computed once.

### Space Complexity: O(amount)

**Example walkthrough:**
```
coins=[1,2,5], amount=5 → 4 ways: (5), (2+2+1), (2+1+1+1), (1+1+1+1+1)
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


<br><br>

---

```code```
