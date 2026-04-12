Find minimum in rotated sorted array.

<br>

> **Key insight:** Binary search: if mid > right → min in right half. Else left half.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Compare mid with right to determine which half has min

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Compare mid with right to determine which half has min`

### Time Complexity: O(log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
