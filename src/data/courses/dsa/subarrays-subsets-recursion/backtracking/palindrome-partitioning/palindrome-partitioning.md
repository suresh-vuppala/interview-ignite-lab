Partition string into all possible palindrome substrings.

<br>

> **Key insight:** Backtracking: for each position, try all palindrome prefixes, recurse on rest.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Backtrack: try palindrome prefix, recurse on suffix

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Backtrack: try palindrome prefix, recurse on suffix`

### Time Complexity: O(N × 2^N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N × 2^N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
