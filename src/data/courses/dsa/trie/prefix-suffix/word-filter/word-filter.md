Design structure supporting prefix and suffix queries.

<br>

> **Key insight:** Trie of all suffix#word combinations.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Insert suffix#word for all suffixes

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Insert suffix#word for all suffixes`

### Time Complexity: O(N×L²)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×L²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N×L²) | O(N×L²) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
