Find shortest paths between ALL pairs of vertices. Handles negative weights (no negative cycles).

<br>

> Input: n=4, weighted adjacency matrix
> Output: n×n distance matrix
> **Key insight:** DP: dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) for each intermediate vertex k. Triple nested loop.

<br>

---

## Constraints
- `1 ≤ V ≤ 500`

<br>

---

## Solution: Triple Loop DP (Optimal for all-pairs)

**Algorithm:** For k=0..V-1: for i=0..V-1: for j=0..V-1: dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

### Time Complexity: O(V³)
**Why?** Triple nested loop.

**Detailed breakdown:** V=500 → 125,000,000 operations — feasible

### Space Complexity: O(V²)

> **Drawback:** O(V³) is only practical for small V (≤500). For larger graphs, run Dijkstra from each source: O(V(V+E)logV).

> **Key Insight for Improvement:** k must be the OUTERMOST loop — this is crucial for correctness. It represents "considering paths through vertices 0..k."

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Use Case |
|-----------|------|----------|
| Floyd-Warshall | O(V³) | All-pairs, small V, negative weights |
| V × Dijkstra | O(V(V+E)logV) | All-pairs, non-negative, sparse |
| V × Bellman-Ford | O(V²×E) | All-pairs, negative weights, large V |

**Key Insights:**
1. **k outermost:** Crucial — represents intermediate vertices considered so far
2. **Negative cycle detection:** If dist[i][i] < 0 for any i → negative cycle
3. **Applications:** All-pairs shortest path, transitive closure

<br><br>

---

```code```
