Design circular queue supporting all operations in O(1).

<br>

> **Key insight:** Same as circular queue with isFull/isEmpty checks.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** count tracks size; full when count==k

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `count tracks size; full when count==k`

### Time Complexity: O(1) per op
**Why?** Each element/state processed efficiently.

### Space Complexity: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) per op | O(k) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
