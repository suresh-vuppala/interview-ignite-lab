Check if s3 is formed by interleaving s1 and s2.

<br>

---

## Solution 1: Recursion — O(2^(m+n))
## Solution 2: DP — dp[i][j] = can first i chars of s1 + first j chars of s2 form first i+j chars of s3.

### Time: O(m × n) | Space: O(m × n) → O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^(m+n)) | O(m+n) | Try both |
| DP | O(mn) | O(n) | Track interleave validity |

<br>
<br>

---

```code```
