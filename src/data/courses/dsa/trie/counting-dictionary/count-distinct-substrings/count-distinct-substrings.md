Count distinct substrings of a string.

<br>

> **Key insight:** Insert all suffixes into trie. Each trie node = distinct prefix = distinct substring.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie of all suffixes, count nodes

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie of all suffixes, count nodes`

### Time Complexity: O(N²)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N²) | O(N²) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
