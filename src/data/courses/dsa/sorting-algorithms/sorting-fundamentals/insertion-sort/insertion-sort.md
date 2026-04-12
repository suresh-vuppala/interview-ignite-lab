Insert each element into its correct position in sorted prefix.

<br>

> **Key insight:** Shift larger elements right, insert current element.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Shift right until correct position found

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Shift right until correct position found`

### Time Complexity: O(N²) worst, O(N) best
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N²) worst, O(N) best | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
