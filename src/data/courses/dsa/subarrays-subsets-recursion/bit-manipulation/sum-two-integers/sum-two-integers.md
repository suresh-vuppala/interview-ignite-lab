Add two integers without using + or - operators.

<br>

> **Key insight:** XOR = sum without carry. AND << 1 = carry. Repeat until carry is 0.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** a^b = sum without carry, (a&b)<<1 = carry

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `a^b = sum without carry, (a&b)<<1 = carry`

### Time Complexity: O(32)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(32) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
