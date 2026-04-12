Find all primes up to N.

<br>

> **Key insight:** Mark multiples as composite starting from each prime.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Mark multiples of each prime starting from p²

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Mark multiples of each prime starting from p²`

### Time Complexity: O(N log log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log log N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
