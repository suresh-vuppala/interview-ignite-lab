Find the longest palindromic substring.

<br>

---

## Solution 1: Check All Substrings — O(n³)
## Solution 2: DP — dp[i][j] = s[i..j] is palindrome. O(n²) time, O(n²) space
## Solution 3: Expand Around Center (Optimal practical)

For each center (n single + n-1 between), expand outward while palindrome.

### Time: O(n²) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| All Substrings | O(n³) | O(1) | Check each substring |
| DP | O(n²) | O(n²) | Build palindrome table |
| Expand Center | O(n²) | O(1) | Expand from each center |

<br>
<br>

---

```code```
