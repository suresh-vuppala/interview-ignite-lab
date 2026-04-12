Reverse all 32 bits of an unsigned integer.

<br>

> **Key insight:** Extract rightmost bit, shift result left, OR with extracted bit. Repeat 32 times.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Extract LSB, build result from MSB

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Extract LSB, build result from MSB`

### Time Complexity: O(32)=O(1)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(32)=O(1) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
