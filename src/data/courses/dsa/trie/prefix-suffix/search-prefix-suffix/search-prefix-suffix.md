Search words matching both prefix and suffix patterns.

<br>

> **Key insight:** Use trie with combined key: for each word, insert all (suffix+'#'+word) variants.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Suffix#Word trick in trie for prefix+suffix search

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Suffix#Word trick in trie for prefix+suffix search`

### Time Complexity: O(N×L²)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N×L²) | O(N×L²) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
