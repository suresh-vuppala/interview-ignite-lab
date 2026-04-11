Count unique paths in m×n grid (can only move right or down).

<br>

---

## Solution 1: Recursion — O(2^(m+n))
## Solution 2: DP — dp[i][j] = dp[i-1][j] + dp[i][j-1]
## Solution 3: Math — C(m+n-2, m-1) — O(min(m,n))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^(m+n)) | O(m+n) | Exponential |
| DP | O(m×n) | O(n) | Bottom-up grid |
| Math | O(min(m,n)) | O(1) | Combinatorics formula |

<br>
<br>

---

```code```
