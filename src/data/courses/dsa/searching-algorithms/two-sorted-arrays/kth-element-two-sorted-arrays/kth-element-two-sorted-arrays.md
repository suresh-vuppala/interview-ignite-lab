Find kth element in two sorted arrays.

<br>

> **Key insight:** Binary search: eliminate k/2 elements from one array each step.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search eliminating k/2 per step

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search eliminating k/2 per step`

### Time Complexity: O(log K)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log K) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
