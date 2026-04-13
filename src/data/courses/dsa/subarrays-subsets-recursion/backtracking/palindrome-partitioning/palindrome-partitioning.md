Partition string into all possible sets of palindromic substrings.

<br>

> s='aab' → [['a','a','b'],['aa','b']]
>
> **Key insight:** Backtracking: at each position, try all palindrome prefixes. If prefix is palindrome, recurse on remaining.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Try all partitions and check

### Time Complexity: O(N × 2^N)

> **Drawback:**
> Same complexity but less organized.

> **Key Insight for Improvement:**
> Backtracking: for each position, try extending palindrome prefix. Only recurse if prefix IS palindrome.

<br>

---

## Solution 2: Backtracking + Palindrome Check (Optimal)

**Intuition:** Backtracking: at each position, try all palindrome prefixes. If prefix is palindrome, recurse on remaining.

**Algorithm:**
1. backtrack(start, current):
2. If start == N: add current copy
3. For end = start to N-1:
   - If s[start..end] is palindrome:
     - Add s[start..end], recurse(end+1), remove

### Time Complexity: O(N × 2^N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
s='aab': 'a' palindrome→recurse('ab'): 'a' pal→recurse('b'): 'b' pal→[a,a,b]
'aa' palindrome→recurse('b'): 'b' pal→[aa,b]
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all partitions and check | O(N × 2^N) | Varies | Baseline |
| Backtracking + Palindrome Check | O(N × 2^N) | O(N) | Optimal |

**Recommended Solution:** Backtracking + Palindrome Check

**Key Insights:**
1. **Only recurse on palindromes:** Pruning non-palindrome prefixes
2. **Precompute palindromes:** DP table for O(1) palindrome checks
3. **LeetCode 131:** Medium backtracking

<br><br>

---

```code```
