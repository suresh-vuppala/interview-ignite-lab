Given a reference to a node in a connected undirected graph, return a deep copy (clone) of the graph.

<br>

> Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
> Output: Deep copy with same structure
> **Key insight:** BFS/DFS with a map from original→clone. When visiting a node, create its clone. For each neighbor: if already cloned, link; if not, clone and recurse/enqueue.

<br>

---

## Constraints
- `1 ≤ N ≤ 100`

<br>

---

## Solution: DFS/BFS with HashMap (Optimal)

**Algorithm:** Map: original node → cloned node. DFS: create clone, recurse on neighbors. If neighbor already in map, use existing clone.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** None.

> **Key Insight for Improvement:** The map serves as both a "visited" set and a lookup for already-cloned nodes. Prevents infinite loops in cyclic graphs.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS + Map | O(V+E) | O(V) |
| BFS + Map | O(V+E) | O(V) |

**Key Insights:**
1. **Map = visited + clone lookup:** One data structure serves both purposes
2. **Deep copy:** New nodes with new pointers — no shared references
3. **Handles cycles:** Map prevents revisiting/recloning

<br><br>

---

```code```
