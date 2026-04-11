Count distinct subsequences of s that equal t.

<br>

---

## Solution 1: Recursion — O(2^n)
## Solution 2: DP — dp[i][j] = ways to form t[0..j-1] from s[0..i-1]. If match: dp[i-1][j-1]+dp[i-1][j]. Else: dp[i-1][j].

### Time: O(m × n) | Space: O(n) with 1D optimization

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^n) | O(n) | Exponential |
| DP | O(mn) | O(n) | Count subsequence matches |

<br>
<br>

---

```code```
