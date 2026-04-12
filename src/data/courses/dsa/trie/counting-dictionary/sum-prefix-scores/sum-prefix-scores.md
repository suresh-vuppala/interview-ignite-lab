For each word, sum count of words having each of its prefixes.

<br>

> **Key insight:** Trie with prefix count. For each word, sum counts along its path.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie prefix counting

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie prefix counting`

### Time Complexity: O(N×L)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N×L) | O(N×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
