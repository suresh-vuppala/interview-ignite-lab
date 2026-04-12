Find kth smallest in row/col sorted matrix.

<br>

> **Key insight:** Min-heap starting with first column. Extract min, push right neighbor.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Min-heap BFS-like exploration of sorted matrix

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Min-heap BFS-like exploration of sorted matrix`

### Time Complexity: O(K log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(K log N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
