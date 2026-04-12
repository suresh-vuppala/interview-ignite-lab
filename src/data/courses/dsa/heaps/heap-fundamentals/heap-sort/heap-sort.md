Sort array using heap. Build max-heap, repeatedly extract max.

<br>

> **Key insight:** Build heap O(N). Extract max N times: swap root with last, heapify down.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Build max-heap + N extractions

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Build max-heap + N extractions`

### Time Complexity: O(N log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
