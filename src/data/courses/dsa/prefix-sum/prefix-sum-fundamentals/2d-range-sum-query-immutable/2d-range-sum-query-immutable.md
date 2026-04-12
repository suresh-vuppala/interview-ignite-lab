2D prefix sum for rectangular region queries.

<br>

> **Key insight:** prefix[i][j] = sum of rectangle (0,0)→(i,j). Query uses inclusion-exclusion.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** 2D prefix + inclusion-exclusion for rectangle queries

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `2D prefix + inclusion-exclusion for rectangle queries`

### Time Complexity: O(1) per query
**Why?** Each element/state processed efficiently.

### Space Complexity: O(M×N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) per query | O(M×N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
