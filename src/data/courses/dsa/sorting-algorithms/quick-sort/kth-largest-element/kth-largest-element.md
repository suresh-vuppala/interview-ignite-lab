Find kth largest using QuickSelect.

<br>

> **Key insight:** Same as kth smallest with adjusted k = N-k+1.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** QuickSelect or min-heap of size K

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `QuickSelect or min-heap of size K`

### Time Complexity: O(N) average
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) average | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
