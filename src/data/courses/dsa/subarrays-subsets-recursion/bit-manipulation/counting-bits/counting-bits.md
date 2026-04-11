Count number of 1-bits for every number from 0 to n.

<br>

---

## Solution 1: Pop Count per Number — O(n log n)
## Solution 2: DP: dp[i] = dp[i >> 1] + (i & 1) — O(n)

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Pop Count | O(n log n) | O(n) | Count bits per number |
| DP | O(n) | O(n) | Reuse result of i/2 |

<br>
<br>

---

```code```
