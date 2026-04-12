Minimize max balls in bag after K operations.

<br>

> **Key insight:** Binary search on answer (max balls). Count operations needed for each limit.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search on max, count ops = ceil(balls/max)-1

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search on max, count ops = ceil(balls/max)-1`

### Time Complexity: O(N log M)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log M) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
