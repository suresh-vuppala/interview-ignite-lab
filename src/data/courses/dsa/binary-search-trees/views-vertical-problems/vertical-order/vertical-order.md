Return nodes grouped by vertical column (horizontal distance), ordered top-to-bottom within each column.

<br>

> **Key insight:** BFS with HD. Group nodes by HD using a map. Sorted map keys give left-to-right column order. BFS ensures top-to-bottom within each column.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution: BFS + HD Group Map (Optimal)

### Time Complexity: O(N log N)
**Why?** Each node visited at most once during traversal.

**Detailed breakdown:** N = 10,000 → ~10,000 operations

### Space Complexity: O(N)

> **Drawback:** None — O(N) traversal is optimal since we must visit all nodes.

> **Key Insight for Improvement:** BFS (level-order) is often simpler than DFS for view problems because it naturally processes level by level.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS/DFS | O(N log N) | O(N) |

**Key Insights:**
1. Views use BFS level-order as the primary technique
2. Column-based problems (top/bottom/vertical) assign horizontal distance
3. First/last at each level determines left/right view

<br><br>

---

```code```
