Implement min-heap and max-heap with insert and extract operations.

<br>

> **Key insight:** Complete binary tree stored in array. Parent=i/2, children=2i,2i+1. Heapify up on insert, down on extract.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Heapify: swap with parent/child to maintain heap property

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Heapify: swap with parent/child to maintain heap property`

### Time Complexity: O(log N) per op
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log N) per op | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
