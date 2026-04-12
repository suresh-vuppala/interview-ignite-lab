Return the bottom view — last node at each horizontal distance (overwrite as BFS goes deeper).

<br>

> **Key insight:** BFS with horizontal distance. LAST node at each HD wins (unlike top view where first wins). Just overwrite the map value at each level.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution: BFS + HD Map — Overwrite (Optimal)

### Time Complexity: O(N)
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
| BFS/DFS | O(N) | O(N) |

**Key Insights:**
1. Views use BFS level-order as the primary technique
2. Column-based problems (top/bottom/vertical) assign horizontal distance
3. First/last at each level determines left/right view

<br><br>

---

```code```
