Check if a number is a power of 2.

<br>

> **Key insight:** Power of 2 has exactly one set bit. n > 0 && (n & (n-1)) == 0.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** n & (n-1) == 0 means exactly one bit set

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `n & (n-1) == 0 means exactly one bit set`

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
