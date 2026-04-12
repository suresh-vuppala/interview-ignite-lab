Search in matrix sorted by rows and columns.

<br>

> **Key insight:** Same staircase search from top-right.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Top-right corner: left if smaller, down if larger

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Top-right corner: left if smaller, down if larger`

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
