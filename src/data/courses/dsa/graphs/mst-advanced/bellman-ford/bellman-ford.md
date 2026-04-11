Find shortest paths from source to all vertices, handling negative edge weights. Detect negative weight cycles.

<br>

---

## Constraints

- `1 ≤ V ≤ 10⁵`
- `0 ≤ E ≤ V×(V-1)` (directed graph)
- `Weights can be negative`
- `Detects negative weight cycles`

<br>

---

## All Possible Edge Cases

1. **No negative edges:** Same result as Dijkstra but slower
2. **Negative cycle:** Report negative cycle detected
3. **Disconnected graph:** Unreachable nodes have distance = infinity
4. **Single node:** Distance = 0
5. **All positive weights:** Works correctly but Dijkstra is faster

<br>

---

```code```
