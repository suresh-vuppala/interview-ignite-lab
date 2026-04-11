Count ways to make amount using given coins (unlimited supply).

<br>

---

## Solution 1: Recursion — O(amount^n)
## Solution 2: DP — dp[i] = number of ways to make sum i. For each coin: dp[i] += dp[i - coin].

### Time: O(n × amount) | Space: O(amount)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(amount^n) | O(amount) | Exponential |
| DP | O(n × amount) | O(amount) | Bottom-up counting |

<br>
<br>

---

```code```
