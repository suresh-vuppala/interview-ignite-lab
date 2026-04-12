Find the Minimum Spanning Tree (MST) using Kruskal's algorithm. MST connects all vertices with minimum total edge weight.

<br>

> Input: n=4, edges=[[0,1,10],[0,2,6],[0,3,5],[1,3,15],[2,3,4]]
> Output: MST edges with total weight 19 (edges: 2-3(4), 0-3(5), 0-1(10))
> **Key insight:** Greedy: sort edges by weight. Process smallest first. Add edge if it doesn't create a cycle (checked via Union-Find). Stop after V-1 edges.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: Sort Edges + DSU (Optimal)

**Algorithm:**
1. Sort all edges by weight (ascending)
2. For each edge (u,v,w) in sorted order: if find(u) ≠ find(v) → add to MST, union(u,v)
3. Stop after V-1 edges added

### Time Complexity: O(E log E)
**Why?** Sorting dominates. DSU operations: O(E × α(V)).

**Detailed breakdown:** E=200,000 → ~200,000 × 18 ≈ 3.6M sort comparisons

### Space Complexity: O(V + E)

> **Drawback:** Requires sorting all edges upfront. For dense graphs, Prim's may be better.

> **Key Insight for Improvement:** Kruskal's is better for sparse graphs (E << V²). Prim's with min-heap is better for dense graphs.

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Best For |
|-----------|------|----------|
| Kruskal's | O(E log E) | Sparse graphs |
| Prim's (heap) | O((V+E) log V) | Dense graphs |

**Key Insights:**
1. **Greedy + DSU:** Sort by weight, use DSU for cycle detection
2. **V-1 edges:** MST always has exactly V-1 edges
3. **Cycle check = DSU:** If both endpoints in same set → skip (would create cycle)

<br><br>

---

```code```
