Check if a graph is bipartite — can nodes be colored with 2 colors such that no two adjacent nodes share the same color?

<br>

> Input: n=4, adj=[[1,3],[0,2],[1,3],[0,2]]
> Output: true (color: 0→A, 1→B, 2→A, 3→B)
> **Key insight:** BFS/DFS coloring. Assign color to start node. Neighbors get opposite color. If a neighbor already has the same color → not bipartite. Equivalent to checking for odd-length cycles.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: BFS 2-Coloring (Optimal)

**Algorithm:** BFS from each unvisited node. Color start with 0. Neighbors get 1-color[node]. If neighbor already colored same → false.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** None — O(V+E) is optimal.

> **Key Insight for Improvement:** Bipartite ↔ no odd-length cycles. 2-coloring is the standard check.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS 2-Color | O(V+E) | O(V) |
| DFS 2-Color | O(V+E) | O(V) |

**Key Insights:**
1. **2-colorable = bipartite = no odd cycles**
2. **Color assignment:** Alternate 0/1 at each BFS level
3. **Handle disconnected:** Check all components

<br><br>

---

```code```
