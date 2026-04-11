Minimum cuts to partition string into palindromes.

<br>

---

## Solution 1: Recursion — Try all cut points O(2^n)
## Solution 2: DP — dp[i] = min cuts for s[0..i]. Precompute isPalin[i][j]. dp[i] = min(dp[j-1]+1) for all j where s[j..i] is palindrome.

### Time: O(n²) | Space: O(n²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^n) | O(n) | Try all partitions |
| DP | O(n²) | O(n²) | Precompute palindromes + cut DP |

<br>
<br>

---

```code```
