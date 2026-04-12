Subset sum using Meet in the Middle for large N.

<br>

> **Key insight:** Split array in half. Generate all subset sums for each half. Two-pointer or binary search to find target.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Split, enumerate both halves, two-pointer match

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Split, enumerate both halves, two-pointer match`

### Time Complexity: O(2^(N/2))
**Why?** Each element/state processed efficiently.

### Space Complexity: O(2^(N/2))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(2^(N/2)) | O(2^(N/2)) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
