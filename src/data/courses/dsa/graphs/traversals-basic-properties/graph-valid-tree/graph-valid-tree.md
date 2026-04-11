Given n nodes and a list of undirected edges, check if these edges form a valid tree. A valid tree has n-1 edges and is connected (no cycles).

<br>

> Input: n=5, edges=[[0,1],[0,2],[0,3],[1,4]]
> Output: true
> **Key insight:** A graph is a tree iff: (1) it has exactly n-1 edges, AND (2) it is connected. Check both conditions.

<br>

---

## Constraints
- `1 ≤ n ≤ 2000`

<br>

---

## Solution: Edge Count + BFS/DFS Connectivity (Optimal)

**Algorithm:**
1. If edges.size() ≠ n-1 → false (wrong edge count)
2. Build adjacency list. BFS/DFS from node 0. Count visited nodes.
3. If visited == n → connected → valid tree

### Time Complexity: O(V + E)
### Space Complexity: O(V + E)

> **Drawback:** None.

> **Key Insight for Improvement:** Union-Find alternative: process each edge. If both endpoints already connected → cycle → false. After all edges, check if single component.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Edge count + BFS | O(V+E) | O(V+E) |
| Union-Find | O(E·α) | O(V) |

**Key Insights:**
1. **Tree = connected + n-1 edges = connected + no cycles**
2. **Quick reject:** If edges ≠ n-1, immediately false
3. **Then verify connectivity:** One BFS/DFS from any node should reach all

<br><br>

---

```code```
