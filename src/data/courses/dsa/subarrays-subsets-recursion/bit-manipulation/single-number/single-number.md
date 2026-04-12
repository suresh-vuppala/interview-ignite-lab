Every element appears twice except one. Find the single one.

<br>

> **Key insight:** XOR all elements. Pairs cancel out (a^a=0). Remaining = single number.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** XOR all: pairs cancel, single remains

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `XOR all: pairs cancel, single remains`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
