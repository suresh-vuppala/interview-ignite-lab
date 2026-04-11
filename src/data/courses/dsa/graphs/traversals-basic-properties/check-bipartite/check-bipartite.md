Check if graph is bipartite (2-colorable).

<br>

---

## Solution 1: BFS Coloring

Assign colors alternately during BFS. If neighbor has same color → not bipartite.

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: DFS Coloring

Same logic with DFS.

### Time: O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS Color | O(V+E) | O(V) | Alternate coloring |
| DFS Color | O(V+E) | O(V) | Recursive coloring |

<br>
<br>

---

```code```
