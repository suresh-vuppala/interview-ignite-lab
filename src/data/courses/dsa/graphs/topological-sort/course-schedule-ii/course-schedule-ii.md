Return a valid course order (topological sort of prerequisite graph).

<br>

---

## Solution 1: DFS Postorder → Reverse

DFS topological sort. If cycle → return [].

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: Kahn's BFS (Preferred)

Collect nodes as they reach in-degree 0. If result size < numCourses → cycle.

### Time: O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Reverse | O(V+E) | O(V) | Postorder gives reverse order |
| Kahn's BFS | O(V+E) | O(V) | Direct order via in-degree |

<br>
<br>

---

```code```
