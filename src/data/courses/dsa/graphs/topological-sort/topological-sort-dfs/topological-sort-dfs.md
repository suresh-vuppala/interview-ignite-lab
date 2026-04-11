Return a topological ordering of a directed acyclic graph (DAG) using DFS.

<br>

> Input: n=6, edges=[[5,2],[5,0],[4,0],[4,1],[2,3],[3,1]]
> Output: [5,4,2,3,1,0] (one valid ordering)
> **Key insight:** DFS postorder + reverse. After fully processing a node (all descendants visited), push to stack. Stack order = topological order.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: DFS Postorder + Reverse (Optimal)

**Algorithm:** DFS from each unvisited node. After recursing all children, push node to stack (postorder). Result = stack order (or reverse postorder).

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** Doesn't detect cycles — assumes DAG. Use detect-cycle first or use Kahn's (which naturally detects cycles).

> **Key Insight for Improvement:** Kahn's BFS alternative: process nodes with in-degree 0 first. Naturally detects cycles (if output < V nodes).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Cycle Detection |
|----------|------|-------|----------------|
| DFS Postorder | O(V+E) | O(V) | No (assumes DAG) |
| Kahn's BFS | O(V+E) | O(V) | Yes (output size < V) |

**Key Insights:**
1. **Postorder = dependencies first:** A node is added AFTER all its dependencies
2. **Reverse postorder = topological order:** Most dependent first
3. **Applications:** Build systems, course scheduling, dependency resolution

<br><br>

---

```code```
