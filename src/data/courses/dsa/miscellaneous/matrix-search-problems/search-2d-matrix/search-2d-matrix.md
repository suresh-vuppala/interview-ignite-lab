Search target in row-sorted, column-sorted matrix.

<br>

> **Key insight:** Start from top-right. If target < current → go left. If target > current → go down.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Staircase search from top-right corner

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Staircase search from top-right corner`

### Time Complexity: O(M+N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(M+N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
