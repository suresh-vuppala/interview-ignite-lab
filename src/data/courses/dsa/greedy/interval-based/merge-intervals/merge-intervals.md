Merge all overlapping intervals.

<br>

> **Key insight:** Sort by start. If current overlaps previous, merge (extend end). Else add new.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Sort + linear scan, extend end on overlap

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Sort + linear scan, extend end on overlap`

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
