Find K closest points to origin.

<br>

> **Key insight:** Max-heap of size K. Push all points, maintain only K closest.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Max-heap size K: if new point closer than top, replace

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Max-heap size K: if new point closer than top, replace`

### Time Complexity: O(N log K)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(K)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log K) | O(K) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
