Find the Minimum Spanning Tree using Prim's algorithm. Grow MST by always adding the cheapest edge from MST to non-MST vertex.

<br>

---

## Constraints

- `1 ≤ V ≤ 10⁵`
- `Connected undirected weighted graph`

<br>

---

## All Possible Edge Cases

1. **Dense graph:** Adjacency matrix + O(V²) Prim's may be better
2. **Sparse graph:** Adjacency list + min-heap O(E log V)
3. **All same weights:** Any spanning tree works
4. **Negative weights:** Works correctly unlike Dijkstra for shortest paths

<br>

---

```code```
