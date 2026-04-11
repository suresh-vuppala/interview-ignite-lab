Minimum cost to multiply chain of matrices.

<br>

---

## Solution 1: Recursion — Try all split points O(2^n)
## Solution 2: DP — dp[i][j] = min cost for matrices i..j. Try all k splits.

### Time: O(n³) | Space: O(n²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^n) | O(n) | Exponential |
| DP | O(n³) | O(n²) | Fill diagonally, try all splits |

<br>
<br>

---

```code```
