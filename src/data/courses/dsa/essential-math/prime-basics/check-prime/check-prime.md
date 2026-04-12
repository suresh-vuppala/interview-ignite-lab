Check if a number is prime.

<br>

> **Key insight:** Check divisibility from 2 to √N.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** No divisor in [2, √N] → prime

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `No divisor in [2, √N] → prime`

### Time Complexity: O(√N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(√N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
