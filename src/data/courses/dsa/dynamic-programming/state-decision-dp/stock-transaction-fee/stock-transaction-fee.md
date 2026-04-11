Buy/sell with transaction fee per trade.

<br>

---

## Solution 1: DP — hold = max(hold, cash - price), cash = max(cash, hold + price - fee)

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hold/Cash DP | O(n) | O(1) | Subtract fee on sell |

<br>
<br>

---

```code```
