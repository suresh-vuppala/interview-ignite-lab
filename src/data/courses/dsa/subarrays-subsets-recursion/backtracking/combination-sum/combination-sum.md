Find all combinations summing to target (unlimited use).

<br>

> **Key insight:** Backtracking: for each candidate, include (recurse with same start) or skip.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Backtrack: include (same index) or skip (next index)

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Backtrack: include (same index) or skip (next index)`

### Time Complexity: O(2^T)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(T)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(2^T) | O(T) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
