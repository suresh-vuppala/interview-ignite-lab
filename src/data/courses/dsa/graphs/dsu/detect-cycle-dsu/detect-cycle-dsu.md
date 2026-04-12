Detect a cycle in an undirected graph using Union-Find.

<br>

> Input: n=4, edges=[[0,1],[1,2],[2,3],[3,1]]
> Output: true
> **Key insight:** Process edges one by one. Before adding edge (u,v): if find(u)==find(v) → they're already connected → adding this edge creates a cycle.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: Union-Find Cycle Check (Optimal)

**Algorithm:** For each edge (u,v): if find(u)==find(v) → cycle. Else union(u,v).

### Time Complexity: O(E × α(V)) ≈ O(E)
### Space Complexity: O(V)

> **Drawback:** None — equivalent to DFS cycle detection.

> **Key Insight for Improvement:** DSU is especially useful when edges are given as a stream (online algorithm). DFS requires the full graph upfront.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS | O(V+E) | O(V) |
| DSU | O(E·α) ≈ O(E) | O(V) |

**Key Insights:**
1. **Same component = cycle:** If u and v already connected before adding edge → cycle
2. **Online algorithm:** Can process edges one at a time
3. **Simpler for edge-list input:** No need to build adjacency list

<br><br>

---

```code```
