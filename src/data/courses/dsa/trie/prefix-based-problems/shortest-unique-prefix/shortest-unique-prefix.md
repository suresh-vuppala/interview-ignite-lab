Find shortest unique prefix for each word.

<br>

> **Key insight:** Insert all words. Prefix is unique when node count == 1.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie with count per node, unique when count==1

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie with count per node, unique when count==1`

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
