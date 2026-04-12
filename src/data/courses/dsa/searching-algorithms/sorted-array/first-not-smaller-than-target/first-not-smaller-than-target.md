Find first element ≥ target (lower_bound).

<br>

> **Key insight:** Binary search: if nums[mid] >= target, search left half.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** lower_bound: first element >= target

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `lower_bound: first element >= target`

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
