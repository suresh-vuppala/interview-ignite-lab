Find minimum operations (insert, delete, replace) to convert word1 to word2.

<br>

> word1='horse', word2='ros' → 3 (horse→rorse→rose→ros)
> **Key insight:** dp[i][j] = 0 if match, else 1 + min(dp[i-1][j] delete, dp[i][j-1] insert, dp[i-1][j-1] replace).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(3^(m+n))

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[i][j] = dp[i-1][j-1] if match, else 1+min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`

<br>

---

## Solution 2: DP — Bottom-up 2D

**Recurrence:** `dp[i][j] = dp[i-1][j-1] if match, else 1+min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`

### Time Complexity: O(m×n)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(n)

**Example walkthrough:**
```
'horse'→'ros': dp[5][3]=3. Delete h, replace o→o, delete r, keep s→nope, replace e→s
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(3^(m+n)) | O(N) stack |
| Memoization | O(m×n) | Same as tabulation |
| Tabulation | O(m×n) | O(n) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state
3. **FAANG critical:** Top-5 string DP problem
4. **Applications:** Spell check, DNA alignment, diff tools

<br><br>

---

```code```
