Find the length of the longest palindromic subsequence in a string.

<br>

> s='bbbab' → 4 ('bbbb')
> **Key insight:** LPS(s) = LCS(s, reverse(s)). Or dp[i][j] = length of LPS in s[i..j]. If s[i]==s[j]: dp[i-1][j-1]+2, else max(dp[i-1][j], dp[i][j-1]).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `LPS = LCS(s, reverse(s))`

<br>

---

## Solution 2: DP — LCS with reversed string

**Recurrence:** `LPS = LCS(s, reverse(s))`

### Time Complexity: O(N²)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(N)

**Example walkthrough:**
```
s='bbbab', rev='babbb'. LCS = 4 = 'bbbb'
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(2^N) | O(N) stack |
| Memoization | O(N²) | Same as tabulation |
| Tabulation | O(N²) | O(N) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
