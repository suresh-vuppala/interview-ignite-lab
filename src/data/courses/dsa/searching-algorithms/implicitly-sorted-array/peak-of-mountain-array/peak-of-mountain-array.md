Find peak element in mountain array.

<br>

> **Key insight:** Binary search: if nums[mid] < nums[mid+1] → peak is right. Else left.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search: ascending side → go right, descending → go left

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search: ascending side → go right, descending → go left`

### Time Complexity: O(log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
