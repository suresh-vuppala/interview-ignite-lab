Find minimum cuts to partition s into palindromic substrings.

<br>

> Standard DP problem
> **Key insight:** dp[i] = min cuts for s[0..i]

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[i] = min(dp[j-1]+1) for all j where s[j..i] is palindrome`

<br>

---

## Solution 2: DP — Bottom-up DP

**Recurrence:** `dp[i] = min(dp[j-1]+1) for all j where s[j..i] is palindrome`

### Time Complexity: O(m×n) or O(N²)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(N) or O(m×n)

**Example walkthrough:**
```
Apply recurrence: dp[i] = min(dp[j-1]+1) for all j where s[j..i] is palindrome
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
