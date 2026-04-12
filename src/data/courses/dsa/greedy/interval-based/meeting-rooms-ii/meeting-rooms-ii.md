Find minimum meeting rooms required.

<br>

> **Key insight:** Sort events by time. Use min-heap of end times. If earliest end ≤ new start, reuse room.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Min-heap of end times tracks active meetings

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Min-heap of end times tracks active meetings`

### Time Complexity: O(N log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
