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
