Regular expression matching with '.' and '*'.

<br>

---

## Solution 1: Recursion — O(exponential)
## Solution 2: DP — dp[i][j] = s[0..i-1] matches p[0..j-1]. Handle '.', '*' transitions.

### Time: O(m × n) | Space: O(m × n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | exponential | O(m+n) | Try all possibilities |
| DP | O(mn) | O(mn) | Memoize match states |

<br>
<br>

---

```code```
