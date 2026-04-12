Find longest word where every prefix is also in dictionary.

<br>

> **Key insight:** Trie insert all words. DFS/BFS to find longest word with all prefixes present (isEnd at each step).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie + DFS checking isEnd at each level

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie + DFS checking isEnd at each level`

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
