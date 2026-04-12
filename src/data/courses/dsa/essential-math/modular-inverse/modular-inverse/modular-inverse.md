Find modular multiplicative inverse.

<br>

> **Key insight:** Fermat's little theorem: a^(-1) = a^(m-2) mod m (when m is prime).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** a^(m-2) mod m using fast exponentiation

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `a^(m-2) mod m using fast exponentiation`

### Time Complexity: O(log m)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log m) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
