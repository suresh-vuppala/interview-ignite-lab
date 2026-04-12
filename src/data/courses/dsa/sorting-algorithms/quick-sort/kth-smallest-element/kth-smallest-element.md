Find kth smallest using QuickSelect.

<br>

> **Key insight:** Partition like QuickSort but only recurse into the side containing k.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** QuickSelect: partition + recurse one side

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `QuickSelect: partition + recurse one side`

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
