Check if string with '(', ')' and '*' (* can be (, ), or empty) is valid.

<br>

> **Key insight:** Track range [lo, hi] of possible open count. lo = max(0, lo-1 on ), hi = hi+1 on (.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Range tracking: lo,hi of possible open parens count

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Range tracking: lo,hi of possible open parens count`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
