Maximize value with fractional items allowed.

<br>

> **Key insight:** Sort by value/weight ratio. Take items greedily, fraction of last if needed.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Sort by value/weight ratio descending

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Sort by value/weight ratio descending`

### Time Complexity: O(N log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
