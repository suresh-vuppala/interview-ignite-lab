Detect if a directed graph contains a cycle.

<br>

> Input: n=4, edges=[[0,1],[1,2],[2,0],[2,3]]
> Output: true (cycle: 0→1→2→0)
> **Key insight:** DFS with three states: WHITE (unvisited), GRAY (in current DFS path), BLACK (fully processed). Back edge to GRAY node = cycle. Or use Kahn's: if topo sort doesn't include all nodes → cycle.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution 1: DFS with Three Colors (Optimal)

**Algorithm:** Color nodes: 0=white, 1=gray (in stack), 2=black (done). If we encounter a gray node → back edge → cycle.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** None.

> **Key Insight for Improvement:** Kahn's BFS alternative: compute in-degrees, process nodes with in-degree 0. If processed < V → cycle exists.

<br>

---

## Solution 2: Kahn's Algorithm (BFS)

**Algorithm:** Count in-degrees. Queue nodes with in-degree 0. Process: decrement neighbors' in-degrees. If any reach 0 → enqueue. If processed < V → cycle.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Method |
|----------|------|-------|--------|
| DFS 3-Color | O(V+E) | O(V) | Back edge to gray = cycle |
| Kahn's BFS | O(V+E) | O(V) | processed < V = cycle |

**Key Insights:**
1. **Directed vs undirected:** Parent check doesn't work for directed — need color states
2. **Gray = in current path:** Back edge to gray means we've found a cycle in current DFS path
3. **Kahn's:** If topo sort can't process all nodes, remaining nodes form cycle(s)

<br><br>

---

```code```
