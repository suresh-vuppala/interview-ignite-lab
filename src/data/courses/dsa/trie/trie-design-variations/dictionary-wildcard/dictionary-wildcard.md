Dictionary supporting wildcard search.

<br>

> **Key insight:** Same as search-wildcard: trie + DFS on '.'.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie + DFS branching on wildcards

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie + DFS branching on wildcards`

### Time Complexity: O(26^dots × L)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(26^dots × L) | O(N×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
