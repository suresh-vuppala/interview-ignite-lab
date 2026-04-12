Sum of scores of all prefixes of each word.

<br>

> **Key insight:** Trie with count at each node = how many words pass through.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie: sum counts along path for each word

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie: sum counts along path for each word`

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
