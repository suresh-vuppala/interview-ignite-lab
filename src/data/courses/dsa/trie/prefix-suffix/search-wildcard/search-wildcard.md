Search in trie supporting '.' wildcard (any single char).

<br>

> **Key insight:** DFS: on '.', try all 26 children. On regular char, follow that child.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** DFS trie with branching on '.' wildcard

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `DFS trie with branching on '.' wildcard`

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
