Build an adjacency list for a weighted graph. Each edge has a weight/cost.

<br>

> Input: n=4, edges=[[0,1,5],[0,2,3],[1,2,1],[2,3,7]]
> Output: {0:[(1,5),(2,3)], 1:[(0,5),(2,1)], 2:[(0,3),(1,1),(3,7)], 3:[(2,7)]}
> **Key insight:** Store (neighbor, weight) pairs instead of just neighbor. Same adjacency list but with weight attached.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: Adjacency List with Weights (Optimal)

**Algorithm:** For each edge (u,v,w): adj[u].push({v,w}). For undirected: also adj[v].push({u,w}).

### Time Complexity: O(V + E)
### Space Complexity: O(V + E)

> **Drawback:** None — standard for weighted graphs.

> **Key Insight for Improvement:** Foundation for Dijkstra, Bellman-Ford, Kruskal, Prim. Always store (neighbor, weight) pairs.

<br>

---

## Complexity Progression Summary

| Representation | Storage per Edge |
|----------------|-----------------|
| Unweighted | neighbor only |
| Weighted | (neighbor, weight) pair |

**Key Insights:**
1. **Pair storage:** adj[u] = list of (v, weight)
2. **Dijkstra needs this:** Priority queue uses weights for relaxation
3. **Negative weights:** Bellman-Ford handles; Dijkstra does not

<br><br>

---

```code```
