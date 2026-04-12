Return the left view of a binary tree — first node visible at each level when viewed from the left.

<br>

> **Key insight:** BFS level-order: first node at each level is visible from the left. Or DFS: track max depth seen, add node if it's the first at a new depth.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution: BFS — First Node per Level (Optimal)

### Time Complexity: O(N)
**Why?** Each node visited at most once during traversal.

**Detailed breakdown:** N = 10,000 → ~10,000 operations

### Space Complexity: O(W)

> **Drawback:** None — O(N) traversal is optimal since we must visit all nodes.

> **Key Insight for Improvement:** BFS (level-order) is often simpler than DFS for view problems because it naturally processes level by level.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS/DFS | O(N) | O(W) |

**Key Insights:**
1. Views use BFS level-order as the primary technique
2. Column-based problems (top/bottom/vertical) assign horizontal distance
3. First/last at each level determines left/right view

<br><br>

---

```code```
