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

## Solution 1: BFS + HashMap

**Intuition:**
The most straightforward approach — bfs approach is valid.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(V+E)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> BFS approach is valid. DFS is simpler recursively.

> **Key Insight for Improvement:**
> Use DFS/BFS with HashMap (Optimal) for O(V + E) time.

<br>

---

## Solution 2: DFS/BFS with HashMap (Optimal)

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
