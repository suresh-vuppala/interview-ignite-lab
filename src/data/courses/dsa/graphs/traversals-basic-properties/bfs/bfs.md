Breadth-First Search traversal of a graph.

<br>

---

## Constraints

- `0 ≤ n ≤ 10⁵`, `0 ≤ edges ≤ 2 × 10⁵`

<br>

---

## Solution 1: Queue-Based BFS (Standard)

**Algorithm:**
1. Start from source, mark visited, enqueue
2. While queue not empty: dequeue → visit → enqueue unvisited neighbors
3. For disconnected graphs: loop over all nodes, BFS from unvisited ones

### Time: O(V + E) | Space: O(V) — visited array + queue

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS Queue | O(V+E) | O(V) | Level-by-level exploration |

<br>
<br>

---

```code```
