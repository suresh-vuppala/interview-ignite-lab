Find shortest paths handling negative weights. Detect negative cycles.

<br>

---

## Solution 1: Bellman-Ford Algorithm

**Algorithm:**
1. dist[src] = 0, all others = ∞
2. Repeat V-1 times: for each edge (u,v,w): if dist[u] + w < dist[v] → relax
3. One more pass: if any edge still relaxes → negative cycle

**Why V-1 iterations?** Shortest path has at most V-1 edges. Each iteration propagates one more edge.

### Time: O(V × E)
### Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Bellman-Ford | O(V×E) | O(V) | V-1 relaxation passes, detects neg cycles |

<br>
<br>

---

```code```
