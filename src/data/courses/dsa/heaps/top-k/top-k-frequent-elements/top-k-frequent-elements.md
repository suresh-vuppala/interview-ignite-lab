Find K most frequent elements.

<br>

> **Key insight:** Count frequencies with hash map. Use min-heap of size K or bucket sort.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** HashMap + min-heap size K, or bucket sort O(N)

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `HashMap + min-heap size K, or bucket sort O(N)`

### Time Complexity: O(N log K) or O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log K) or O(N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
