Modular arithmetic: addition, subtraction, multiplication.

<br>

> **Key insight:** (a+b)%m = (a%m + b%m)%m. Same for multiplication. Subtraction: add m before mod.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Distribute mod over +, -, ×

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Distribute mod over +, -, ×`

### Time Complexity: O(1) per op
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) per op | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
