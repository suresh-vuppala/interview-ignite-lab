Design autocomplete: given prefix, return top-3 hot sentences.

<br>

> **Key insight:** Trie + frequency tracking. DFS from prefix node to find all completions.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie + DFS from prefix node, sort by frequency

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie + DFS from prefix node, sort by frequency`

### Time Complexity: O(P + N log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(P + N log N) | O(N×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
