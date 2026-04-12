Distribute minimum candies. Higher-rated child gets more than neighbors.

<br>

> **Key insight:** Two passes: left-to-right (handle left neighbor), right-to-left (handle right neighbor). Take max.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Two passes: L→R for left constraint, R→L for right

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Two passes: L→R for left constraint, R→L for right`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
