Find the length of the longest common subsequence of two strings.

<br>

> text1='abcde', text2='ace' → 3 ('ace')
> **Key insight:** dp[i][j] = dp[i-1][j-1]+1 if match, else max(dp[i-1][j], dp[i][j-1]). Match extends LCS, mismatch takes best without one char.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^(m+n))

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[i][j] = dp[i-1][j-1]+1 if s1[i]==s2[j], else max(dp[i-1][j], dp[i][j-1])`

<br>

---

## Solution 2: DP — 2D DP with 1D space optimization

**Recurrence:** `dp[i][j] = dp[i-1][j-1]+1 if s1[i]==s2[j], else max(dp[i-1][j], dp[i][j-1])`

### Time Complexity: O(m×n)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(min(m,n))

**Example walkthrough:**
```
'abcde' vs 'ace': match a(1), skip b, match c(2), skip d, match e(3) → LCS=3
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(2^(m+n)) | O(N) stack |
| Memoization | O(m×n) | Same as tabulation |
| Tabulation | O(m×n) | O(min(m,n)) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state
3. **Foundation for:** Edit distance, diff algorithms, DNA sequence alignment

<br><br>

---

```code```
