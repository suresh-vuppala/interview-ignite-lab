Count pairs (i,j) where i<j but a[i]>a[j].

<br>

> **Key insight:** Modified merge sort: during merge, count inversions across halves.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Baseline approach is less efficient — see optimal solution below.

> **Key Insight for Improvement:** Merge sort: when right element comes first, inversions += remaining left

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Merge sort: when right element comes first, inversions += remaining left`

### Time Complexity: O(N log N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
