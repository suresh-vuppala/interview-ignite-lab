Count pairs where word[i] is both prefix and suffix of word[j].

<br>

> **Key insight:** For each pair, check prefix and suffix conditions.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Trie or direct string comparison

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Trie or direct string comparison`

### Time Complexity: O(N²×L)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N²×L) | O(N×L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
