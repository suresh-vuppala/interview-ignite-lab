Shortest path when edge weights are 0 or 1 only.

<br>

---

## Solution 1: Dijkstra — Works but O((V+E) log V) is overkill

<br>

---

## Solution 2: 0-1 BFS with Deque (Optimal)

**Intuition:** Use deque instead of priority queue. Weight-0 edges → push to front. Weight-1 edges → push to back. This maintains sorted order naturally.

### Time: O(V + E) — no log factor!
### Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Dijkstra | O((V+E)log V) | O(V) | General but heavy |
| 0-1 BFS Deque | O(V+E) | O(V) | Deque replaces heap for 0/1 weights |

<br>
<br>

---

```code```
