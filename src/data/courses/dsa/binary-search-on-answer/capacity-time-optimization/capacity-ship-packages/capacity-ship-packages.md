Find minimum ship capacity to ship within D days.

<br>

> **Key insight:** Binary search on capacity. Check if feasible with given capacity.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search on capacity, greedy day assignment

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search on capacity, greedy day assignment`

### Time Complexity: O(N log S)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log S) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
