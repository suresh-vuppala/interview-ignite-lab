Find median of two sorted arrays in O(log(min(m,n))).

<br>

> **Key insight:** Binary search on partition of smaller array. Ensure left half ≤ right half.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search on smaller array partition

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search on smaller array partition`

### Time Complexity: O(log(min(m,n)))
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log(min(m,n))) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
