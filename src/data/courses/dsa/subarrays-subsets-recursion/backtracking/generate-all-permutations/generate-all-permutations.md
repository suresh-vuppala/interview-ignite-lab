Generate all permutations of an array.

<br>

> **Key insight:** Backtracking: for each position, try all unused elements. Swap-based approach.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Swap element at pos with each remaining, recurse

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Swap element at pos with each remaining, recurse`

### Time Complexity: O(N!)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N!) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
