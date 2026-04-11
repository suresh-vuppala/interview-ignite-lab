Find shortest paths from source to all vertices (non-negative weights).

<br>

---

## Solution 1: Naive — Relax All Vertices V Times

For each unprocessed vertex, find min distance, relax neighbors.

### Time: O(V²) | Space: O(V)

<br>

---

## Solution 2: Min-Heap (Optimal for Sparse Graphs)

**Intuition:** Use priority queue to always process the closest unvisited vertex.

**Algorithm:**
1. dist[src] = 0, all others = ∞
2. Push (0, src) to min-heap
3. While heap not empty:
   - Pop (d, u) — skip if d > dist[u]
   - For each neighbor v: if dist[u] + w < dist[v] → update, push

### Time: O((V + E) log V) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Naive | O(V²) | O(V) | Linear scan for min |
| Min-Heap | O((V+E)log V) | O(V) | Heap gives min in O(log V) |

<br>
<br>

---

```code```
