Divide array in half, sort each, merge sorted halves.

<br>

> **Key insight:** Divide and conquer. Merge two sorted halves in O(N).

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Baseline approach is less efficient — see optimal solution below.

> **Key Insight for Improvement:** Split, recursively sort, merge

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Split, recursively sort, merge`

### Time Complexity: O(N log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
