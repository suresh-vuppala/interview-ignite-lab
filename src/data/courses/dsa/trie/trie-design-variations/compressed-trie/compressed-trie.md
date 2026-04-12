Implement compressed (radix) trie to save space.

<br>

> **Key insight:** Merge single-child chains into one edge with multi-char label.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Merge single-child paths into edge labels

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Merge single-child paths into edge labels`

### Time Complexity: O(L) per op
**Why?** Each element/state processed efficiently.

### Space Complexity: O(total chars)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(L) per op | O(total chars) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
