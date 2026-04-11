0-1 Knapsack but items can be used unlimited times.

<br>

---

## Solution 1: Recursion + Memo
## Solution 2: DP — dp[w] = max value for capacity w. Iterate coins left-to-right with inner loop forward.

### Time: O(n × W) | Space: O(W)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Memo | O(n × W) | O(n × W) | Memoize states |
| DP 1D | O(n × W) | O(W) | Forward iteration allows reuse |

<br>
<br>

---

```code```
