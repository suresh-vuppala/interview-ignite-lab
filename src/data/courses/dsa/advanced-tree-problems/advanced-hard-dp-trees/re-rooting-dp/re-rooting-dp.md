Solve tree DP for all possible roots efficiently.

<br>

> **Key insight:** Compute answer for root 0. Re-root: adjust answer when moving root to child.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** DP from root + transition formula when re-rooting to child

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `DP from root + transition formula when re-rooting to child`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
