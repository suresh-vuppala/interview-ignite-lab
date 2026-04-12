Sort by repeatedly swapping adjacent elements.

<br>

> **Key insight:** Compare adjacent pairs, swap if out of order. Repeat until no swaps needed.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Nested loops: outer for passes, inner for comparisons

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Nested loops: outer for passes, inner for comparisons`

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
