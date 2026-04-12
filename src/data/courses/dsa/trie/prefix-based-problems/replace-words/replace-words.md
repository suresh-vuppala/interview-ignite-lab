Replace words in sentence with their shortest root from dictionary.

<br>

> **Key insight:** Build trie from dictionary. For each word, find shortest prefix in trie.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie of roots, search for shortest prefix match

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie of roots, search for shortest prefix match`

### Time Complexity: O(N×L)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(D×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N×L) | O(D×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
