Find if word exists in grid by adjacent cells.

<br>

> **Key insight:** Backtracking: DFS from each cell matching first char.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** DFS from matching cells, mark visited, backtrack

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `DFS from matching cells, mark visited, backtrack`

### Time Complexity: O(M×N×4^L)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(M×N×4^L) | O(L) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
