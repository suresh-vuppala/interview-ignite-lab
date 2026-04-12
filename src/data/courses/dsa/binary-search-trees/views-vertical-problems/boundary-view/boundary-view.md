Print boundary nodes: left boundary + leaves + right boundary (anti-clockwise). Same as boundary traversal in Trees module.

<br>

> **Key insight:** Three-part: left boundary (top-down, non-leaf), all leaves (left to right), right boundary (bottom-up, non-leaf). Same algorithm as Trees boundary-traversal.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution: Three-Part Traversal (Optimal)

### Time Complexity: O(N)
**Why?** Each node visited at most once during traversal.

**Detailed breakdown:** N = 10,000 → ~10,000 operations

### Space Complexity: O(H)

> **Drawback:** None — O(N) traversal is optimal since we must visit all nodes.

> **Key Insight for Improvement:** BFS (level-order) is often simpler than DFS for view problems because it naturally processes level by level.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS/DFS | O(N) | O(H) |

**Key Insights:**
1. Views use BFS level-order as the primary technique
2. Column-based problems (top/bottom/vertical) assign horizontal distance
3. First/last at each level determines left/right view

<br><br>

---

```code```
