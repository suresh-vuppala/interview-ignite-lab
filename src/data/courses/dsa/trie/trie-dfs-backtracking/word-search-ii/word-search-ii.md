Find all words from dictionary in a grid.

<br>

> **Key insight:** Build trie from words. DFS from each cell, follow trie.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie + grid DFS, prune branches with no children

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie + grid DFS, prune branches with no children`

### Time Complexity: O(M×N×4^L)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(W×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(M×N×4^L) | O(W×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
