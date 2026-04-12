Sort a linked list in O(N log N).

<br>

> **Key insight:** Merge sort: find middle, split, recursively sort, merge.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Merge sort on linked list — split at middle

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Merge sort on linked list — split at middle`

### Time Complexity: O(N log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(log N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) | O(log N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
