Suggest products by prefix as user types.

<br>

> **Key insight:** Trie + DFS to find top-3 lexicographic matches for each prefix.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie insert + DFS for sorted suggestions

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie insert + DFS for sorted suggestions`

### Time Complexity: O(N×L + M×3)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N×L + M×3) | O(N×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
