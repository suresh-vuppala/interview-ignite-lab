Implement stack using a single queue.

<br>

> **Key insight:** After push, rotate queue: move all old elements behind new one.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Push O(N) rotation, Pop O(1)

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Push O(N) rotation, Pop O(1)`

### Time Complexity: Push O(N), Pop O(1)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | Push O(N), Pop O(1) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
