Find time for signal to reach all nodes from source (Dijkstra application).

<br>

---

## Solution 1: Dijkstra (Standard)

Run Dijkstra from source. Answer = max(dist[v]) for all reachable v. If any unreachable → -1.

### Time: O((V + E) log V) | Space: O(V + E)

<br>

---

## Solution 2: Bellman-Ford (if negative weights possible)

### Time: O(V × E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Dijkstra | O((V+E)log V) | O(V+E) | Standard SSSP |
| Bellman-Ford | O(V×E) | O(V) | Handles negatives |

<br>
<br>

---

```code```
