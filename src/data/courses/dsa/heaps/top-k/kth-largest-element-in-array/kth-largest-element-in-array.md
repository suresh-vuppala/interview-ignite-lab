Find the Kth largest element.

<br>

> **Key insight:** Min-heap of size K. After processing all elements, heap top = Kth largest. Or QuickSelect O(N) avg.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Min-heap size K or QuickSelect partition

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Min-heap size K or QuickSelect partition`

### Time Complexity: O(N) avg QuickSelect
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) avg QuickSelect | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
