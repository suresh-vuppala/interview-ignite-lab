Word break using trie for dictionary lookup.

<br>

> **Key insight:** Build trie from dictionary. DP with trie-accelerated prefix matching.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie for O(L) prefix check + DP

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie for O(L) prefix check + DP`

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
