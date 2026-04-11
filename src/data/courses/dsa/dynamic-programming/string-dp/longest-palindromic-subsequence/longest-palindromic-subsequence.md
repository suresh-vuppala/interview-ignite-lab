Find length of longest palindromic subsequence.

<br>

---

## Solution 1: Recursion + Memo
## Solution 2: DP — dp[i][j] = LPS length for s[i..j]. If s[i]==s[j]: dp[i-1][j-1]+2. Else max(dp[i+1][j], dp[i][j-1]).

### Time: O(n²) | Space: O(n²) → O(n) with 1D optimization

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Memo | O(n²) | O(n²) | Cache subproblems |
| DP | O(n²) | O(n) | Bottom-up with space opt |

<br>
<br>

---

```code```
