Find all paths from (0,0) to (N-1,N-1) in a maze.

<br>

> **Key insight:** Backtracking with visited tracking. Try all 4 directions.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** DFS + mark visited + backtrack

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `DFS + mark visited + backtrack`

### Time Complexity: O(4^(N²))
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(4^(N²)) | O(N²) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
