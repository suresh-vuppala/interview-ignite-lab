Find shortest paths between all pairs of vertices. Handles negative edges. Can detect negative weight cycles (diagonal becomes negative), but shortest paths are undefined if a negative cycle exists on the path.

<br>

---

## Constraints

- `1 ≤ V ≤ 500`
- `Weights can be negative`
- `Works for directed and undirected graphs`

<br>

---

## All Possible Edge Cases

1. **Negative cycle:** Diagonal becomes negative
2. **Disconnected nodes:** Distance remains infinity
3. **Single node:** dist[0][0] = 0
4. **Dense graph:** O(V³) may be acceptable for V ≤ 500
5. **All edges same weight:** Equivalent to BFS shortest path

<br>

---

```code```
