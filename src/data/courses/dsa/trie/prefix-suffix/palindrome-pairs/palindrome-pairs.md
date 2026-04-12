Find all pairs of words that form palindromes when concatenated.

<br>

> **Key insight:** Trie of reversed words. For each word, check if prefix matches reversed word in trie.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie of reversed words + palindrome suffix check

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie of reversed words + palindrome suffix check`

### Time Complexity: O(N×L²)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N×L²) | O(N×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
