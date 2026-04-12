Find all divisors of a number.

<br>

> **Key insight:** Check from 1 to √N. If i divides N, both i and N/i are divisors.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Iterate 1..√N, add i and N/i

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Iterate 1..√N, add i and N/i`

### Time Complexity: O(√N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(√N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(√N) | O(√N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
