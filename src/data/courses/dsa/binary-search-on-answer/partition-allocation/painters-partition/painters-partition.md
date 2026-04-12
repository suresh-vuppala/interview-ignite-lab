Minimize maximum time for painters to paint boards.

<br>

> **Key insight:** Same as allocate pages — binary search on answer.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search on max time, greedy assignment

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search on max time, greedy assignment`

### Time Complexity: O(N log S)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log S) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
