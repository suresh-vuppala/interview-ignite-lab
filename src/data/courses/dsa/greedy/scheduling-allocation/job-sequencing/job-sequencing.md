Schedule jobs with deadlines and profits to maximize profit.

<br>

> **Key insight:** Sort by profit descending. For each job, find latest available slot before deadline.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Sort by profit, greedily assign to latest available slot

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Sort by profit, greedily assign to latest available slot`

### Time Complexity: O(N²) or O(N log N) with DSU
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N²) or O(N log N) with DSU | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
