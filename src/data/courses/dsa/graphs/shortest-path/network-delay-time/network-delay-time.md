Given a network of n nodes and directed weighted edges, find the time for a signal to reach all nodes from a source. Return -1 if not all nodes reachable.

<br>

> Input: times=[[2,1,1],[2,3,1],[3,4,1]], n=4, k=2
> Output: 2
> **Key insight:** Dijkstra from source k. Answer = max(dist[i]) for all i. If any dist[i] = ∞ → return -1.

<br>

---

## Constraints
- `1 ≤ n ≤ 100`, `1 ≤ times.length ≤ 6000`

<br>

---

## Solution: Dijkstra + Max Distance (Optimal)

**Algorithm:** Run Dijkstra from k. Return max of all distances. If any node unreachable → -1.

### Time Complexity: O((V+E) log V)
### Space Complexity: O(V + E)

> **Drawback:** None — direct Dijkstra application.

> **Key Insight for Improvement:** For small n, even O(V²) Dijkstra works. This is a pure application problem.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Dijkstra | O((V+E)logV) | O(V+E) |

**Key Insights:**
1. **Direct Dijkstra application:** Find SSSP, then answer = max distance
2. **Check reachability:** If any dist = ∞ → -1
3. **1-indexed nodes:** Remember to handle 1-based indexing

<br><br>

---

```code```
