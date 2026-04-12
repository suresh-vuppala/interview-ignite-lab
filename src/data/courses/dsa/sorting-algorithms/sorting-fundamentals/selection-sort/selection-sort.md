Find minimum in unsorted portion, swap with front.

<br>

> **Key insight:** Select minimum from remaining, place at correct position.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Find min in [i..N], swap with position i

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Find min in [i..N], swap with position i`

### Time Complexity: O(N²)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N²) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
