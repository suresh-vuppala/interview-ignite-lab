Detect cycle in a directed graph.

<br>

---

## Solution 1: DFS with Three Colors

**Colors:** White (unvisited), Gray (in current path), Black (finished).
If we visit a Gray node → back edge → cycle.

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: Kahn's Algorithm (Topological Sort)

If topological sort doesn't include all nodes → cycle exists.

### Time: O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS 3-Color | O(V+E) | O(V) | Gray = in-path detection |
| Kahn's BFS | O(V+E) | O(V) | Incomplete topo sort → cycle |

<br>
<br>

---

```code```
