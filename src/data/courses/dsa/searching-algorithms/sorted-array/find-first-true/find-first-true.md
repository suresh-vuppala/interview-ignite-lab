Find first element satisfying a boolean condition in sorted array.

<br>

> **Key insight:** Binary search: if condition(mid), search left. Else search right.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search for first True in monotonic boolean array

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search for first True in monotonic boolean array`

### Time Complexity: O(log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
