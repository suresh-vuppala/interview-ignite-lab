Maximize profit by cutting rod of length n into pieces.

<br>

---

## Solution 1: Recursion — Try all cut positions O(2^n)
## Solution 2: DP — dp[i] = max profit for length i. dp[i] = max(price[j] + dp[i-j]) for j=1..i.

### Time: O(n²) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^n) | O(n) | Try all cuts |
| DP | O(n²) | O(n) | Optimal substructure |

<br>
<br>

---

```code```
