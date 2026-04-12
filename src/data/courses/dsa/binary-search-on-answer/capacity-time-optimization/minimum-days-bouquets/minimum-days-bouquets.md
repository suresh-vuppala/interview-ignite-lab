Minimum days to make M bouquets of K adjacent flowers.

<br>

> **Key insight:** Binary search on days. Check if enough adjacent bloomed flowers.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search on days, greedy adjacent counting

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search on days, greedy adjacent counting`

### Time Complexity: O(N log D)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log D) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
