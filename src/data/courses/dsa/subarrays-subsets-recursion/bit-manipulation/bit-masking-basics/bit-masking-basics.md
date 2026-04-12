Understand AND, OR, XOR, NOT, left/right shift operations.

<br>

> **Key insight:** AND masks bits, OR sets bits, XOR toggles bits, shift multiplies/divides by 2.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** AND(&), OR(|), XOR(^), NOT(~), <<, >>

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `AND(&), OR(|), XOR(^), NOT(~), <<, >>`

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
