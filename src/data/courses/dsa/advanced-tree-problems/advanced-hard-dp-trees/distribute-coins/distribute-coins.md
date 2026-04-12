Move coins so each node has exactly one. Minimize moves.

<br>

> **Key insight:** Postorder: excess = node.val + left_excess + right_excess - 1. Total moves = sum of |excess|.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Postorder: moves += |excess| at each node

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Postorder: moves += |excess| at each node`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(H) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
