Trie with countWordsEqual and countWordsStartingWith.

<br>

> **Key insight:** Track wordCount and prefixCount at each node.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Increment prefixCount on insert, wordCount at end

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Increment prefixCount on insert, wordCount at end`

### Time Complexity: O(L) per op
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(L) per op | O(N×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
