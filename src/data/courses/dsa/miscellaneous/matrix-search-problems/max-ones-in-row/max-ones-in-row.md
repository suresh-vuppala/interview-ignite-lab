Find row with maximum number of 1s in a binary matrix (rows sorted).

<br>

> **Key insight:** Start from top-right. Move left while 1, move down otherwise. Track row.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Staircase: move left on 1 (better row), down on 0

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Staircase: move left on 1 (better row), down on 0`

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
