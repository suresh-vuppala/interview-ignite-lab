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

## All Possible Edge Cases
1. **One string empty:** LCS = 0
2. **Identical strings:** LCS = length
3. **No common characters:** LCS = 0
4. **One is subsequence of other**

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

### Time Complexity: O(2^(m+n))
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
