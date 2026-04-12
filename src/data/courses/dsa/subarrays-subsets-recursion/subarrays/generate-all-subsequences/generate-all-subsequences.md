Generate all subsequences using recursion.

<br>

> **Key insight:** For each element: include or exclude. Recurse on remaining.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Include/exclude each element → 2^N subsequences

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Include/exclude each element → 2^N subsequences`

### Time Complexity: O(2^N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(2^N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
