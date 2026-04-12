Search in sorted array by halving search space.

<br>

> **Key insight:** Compare with middle, eliminate half each step.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** lo, hi, mid = (lo+hi)/2, eliminate half

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `lo, hi, mid = (lo+hi)/2, eliminate half`

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
