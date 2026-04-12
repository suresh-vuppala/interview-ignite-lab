Count the number of 1-bits in an integer.

<br>

> **Key insight:** Brian Kernighan's: n = n & (n-1) removes lowest set bit. Count iterations.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** n & (n-1) clears lowest set bit each time

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `n & (n-1) clears lowest set bit each time`

### Time Complexity: O(set bits)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(set bits) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
