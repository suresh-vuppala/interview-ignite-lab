Split array into K subarrays minimizing the maximum sum.

<br>

> **Key insight:** Binary search on answer (max sum). Greedy: count subarrays within limit.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search on max sum, greedy split counting

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search on max sum, greedy split counting`

### Time Complexity: O(N log S)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log S) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
