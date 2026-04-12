Implement Trie with insert, search, startsWith.

<br>

> **Key insight:** Node has children[26] and isEnd flag. Insert: create path. Search: follow path.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** children array + isEnd flag per node

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `children array + isEnd flag per node`

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
