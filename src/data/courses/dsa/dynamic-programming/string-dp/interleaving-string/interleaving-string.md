Check if s3 is formed by interleaving s1 and s2.

<br>

> Standard DP problem
> **Key insight:** dp[i][j] = True if s3[0..i+j-1] can be formed by interleaving s1[0..i-1] and s2[0..j-1]

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[i][j] = (dp[i-1][j] and s1[i-1]==s3[i+j-1]) or (dp[i][j-1] and s2[j-1]==s3[i+j-1])`

<br>

---

## Solution 2: DP — Bottom-up DP

**Recurrence:** `dp[i][j] = (dp[i-1][j] and s1[i-1]==s3[i+j-1]) or (dp[i][j-1] and s2[j-1]==s3[i+j-1])`

### Time Complexity: O(m×n) or O(N²)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(N) or O(m×n)

**Example walkthrough:**
```
Apply recurrence: dp[i][j] = (dp[i-1][j] and s1[i-1]==s3[i+j-1]) or (dp[i][j-1] and s2[j-1]==s3[i+j-1])
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(2^N) | O(N) stack |
| Memoization | O(m×n) or O(N²) | Same as tabulation |
| Tabulation | O(m×n) or O(N²) | O(N) or O(m×n) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
