Convert between decimal and binary representations.

<br>

> **Key insight:** Decimal→Binary: divide by 2, collect remainders. Binary→Decimal: multiply by powers of 2.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Repeated division by 2 / positional value sum

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Repeated division by 2 / positional value sum`

### Time Complexity: O(log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(log N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log N) | O(log N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
