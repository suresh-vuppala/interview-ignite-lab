Maximize profit with at most k transactions.

<br>

---

## Solution 1: If k >= n/2 → unlimited (greedy)
## Solution 2: DP — dp[t][d] = max profit on day d with t transactions. buy[t] and sell[t] states.

### Time: O(n × k) | Space: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Greedy (k large) | O(n) | O(1) | Unlimited when k ≥ n/2 |
| DP states | O(nk) | O(k) | Buy/sell states per transaction |

<br>
<br>

---

```code```
