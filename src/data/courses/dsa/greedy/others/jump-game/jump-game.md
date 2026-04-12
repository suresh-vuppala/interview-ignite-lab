Can you reach the last index? Each element = max jump length.

<br>

> **Key insight:** Track farthest reachable index. If current > farthest → false.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Greedy: track maxReach, if i > maxReach → false

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Greedy: track maxReach, if i > maxReach → false`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
