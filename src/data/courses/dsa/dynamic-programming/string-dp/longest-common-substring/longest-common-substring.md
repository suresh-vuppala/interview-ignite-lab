Find the length of the longest common substring (contiguous) of two strings.

<br>

> s1='abcdef', s2='zbcdf' → 3 ('bcd')
> **Key insight:** dp[i][j] = dp[i-1][j-1]+1 if match, else 0. Substring must be contiguous — reset to 0 on mismatch.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **No common substring:** length = 0
2. **One string contains other entirely**
3. **Single character strings**
4. **Multiple substrings of same max length**

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

### Time Complexity: O(m×n)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: DP — 2D DP

**Recurrence:** `dp[i][j] = dp[i-1][j-1]+1 if s1[i]==s2[j], else 0`

### Time Complexity: O(m×n)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(n)

**Example walkthrough:**
```
Track max dp value. Unlike LCS, mismatch resets count to 0.
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(m×n) | O(N) stack |
| Memoization | O(m×n) | Same as tabulation |
| Tabulation | O(m×n) | O(n) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
