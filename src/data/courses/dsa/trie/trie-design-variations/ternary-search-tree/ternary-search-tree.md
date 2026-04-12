Implement ternary search tree as trie alternative.

<br>

> **Key insight:** Three children: less-than, equal, greater-than. More space-efficient than 26-child trie.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** 3 pointers per node: lt, eq, gt

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `3 pointers per node: lt, eq, gt`

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
