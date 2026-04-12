Circular route with gas stations. Find starting station to complete circuit.

<br>

> **Key insight:** If total gas ≥ total cost, solution exists. Track running surplus; reset start when it goes negative.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Running surplus: reset start at deficit, total ≥ 0 guarantees solution

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Running surplus: reset start at deficit, total ≥ 0 guarantees solution`

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
