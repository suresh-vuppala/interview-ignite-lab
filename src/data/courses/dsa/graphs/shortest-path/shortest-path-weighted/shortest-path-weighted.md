Find shortest path in weighted graph (general).

<br>

---

## Solution 1: Dijkstra — Non-negative weights, O((V+E) log V)
## Solution 2: Bellman-Ford — Handles negative weights, O(V × E)
## Solution 3: Floyd-Warshall — All-pairs, O(V³)

**Which to use:**
- Non-negative, single source → Dijkstra
- Negative edges, single source → Bellman-Ford
- All pairs → Floyd-Warshall
- Weights 0/1 only → 0-1 BFS

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Space | Use Case |
|-----------|------|-------|----------|
| Dijkstra | O((V+E)log V) | O(V) | Non-negative, single source |
| Bellman-Ford | O(V×E) | O(V) | Negative edges, single source |
| Floyd-Warshall | O(V³) | O(V²) | All pairs |
| 0-1 BFS | O(V+E) | O(V) | Weights are 0 or 1 |

<br>
<br>

---

```code```
