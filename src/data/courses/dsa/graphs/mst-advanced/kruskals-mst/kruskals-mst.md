Find Minimum Spanning Tree using Kruskal's algorithm.

<br>

---

## Solution 1: Kruskal's (Sort Edges + DSU)

**Intuition:** Sort edges by weight. Add edges greedily if they don't form a cycle (checked via DSU).

**Algorithm:**
1. Sort all edges by weight
2. For each edge (u, v, w):
   - If find(u) != find(v) → union(u, v), add to MST
   - Stop when MST has V-1 edges

### Time: O(E log E) — dominated by sort
### Space: O(V) — DSU

<br>

---

## Solution 2: Prim's Algorithm (Alternative)

See prims-mst.

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Space | Best For |
|-----------|------|-------|----------|
| Kruskal's | O(E log E) | O(V) | Sparse graphs |
| Prim's | O(E log V) | O(V) | Dense graphs |

<br>
<br>

---

```code```
