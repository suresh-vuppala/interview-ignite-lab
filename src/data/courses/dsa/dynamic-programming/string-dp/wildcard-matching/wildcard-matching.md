Implement wildcard pattern matching with '?' (any single char) and '*' (any sequence including empty).

<br>

> Standard DP problem
> **Key insight:** dp[i][j] = True if s[0..i-1] matches p[0..j-1]

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **Pattern is all *:** matches anything
2. **No wildcards:** exact match only
3. **Empty string with * pattern:** true
4. **Consecutive * characters**

<br>

---

## Solution 1: Recursion (Brute Force)

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: DP — Bottom-up DP

**Recurrence:** `dp[i][j]: if p[j]=='*': dp[i-1][j] or dp[i][j-1]; if p[j]=='?' or match: dp[i-1][j-1]`

### Time Complexity: O(m×n) or O(N²)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(N) or O(m×n)

**Example walkthrough:**
```
Apply recurrence: dp[i][j]: if p[j]=='*': dp[i-1][j] or dp[i][j-1]; if p[j]=='?' or match: dp[i-1][j-1]
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
