Wildcard matching with '?' and '*'.

<br>

---

## Solution 1: Recursion + Memo
## Solution 2: DP — dp[i][j] = s[0..i-1] matches p[0..j-1]. '*' matches empty or one more char.

### Time: O(m × n) | Space: O(m × n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | exponential | O(m+n) | Branching on '*' |
| DP | O(mn) | O(mn) | Table of match states |

<br>
<br>

---

```code```
