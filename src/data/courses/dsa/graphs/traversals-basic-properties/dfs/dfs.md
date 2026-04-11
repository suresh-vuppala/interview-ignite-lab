Depth-First Search traversal of a graph.

<br>

---

## Solution 1: Recursive DFS

Mark visited, recurse on unvisited neighbors.

### Time: O(V + E) | Space: O(V) — visited + recursion stack

<br>

---

## Solution 2: Iterative DFS (Stack)

Use explicit stack instead of recursion. Same logic.

### Time: O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(V+E) | O(V) | Natural graph recursion |
| Iterative | O(V+E) | O(V) | No recursion limit |

<br>
<br>

---

```code```
