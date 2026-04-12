Check if kth bit is set, set it, unset it, or toggle it.

<br>

> **Key insight:** Check: n & (1<<k). Set: n | (1<<k). Unset: n & ~(1<<k). Toggle: n ^ (1<<k).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Bitmask operations with (1 << k)

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Bitmask operations with (1 << k)`

### Time Complexity: O(1)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
