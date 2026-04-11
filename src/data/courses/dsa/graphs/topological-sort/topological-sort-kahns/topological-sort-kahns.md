Return a topological ordering using Kahn's algorithm (BFS-based). Also detects cycles.

<br>

> Input: n=6, edges=[[5,2],[5,0],[4,0],[4,1],[2,3],[3,1]]
> Output: [4,5,2,0,3,1] (one valid ordering)
> **Key insight:** Start from nodes with in-degree 0 (no dependencies). Process them, decrement neighbors' in-degrees. New in-degree-0 nodes are enqueued. If output < V → cycle.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: Kahn's BFS (Optimal)

**Algorithm:**
1. Compute in-degrees. Enqueue all nodes with in-degree 0.
2. While queue: dequeue node → add to result → decrement neighbors' in-degrees → enqueue new zero-in-degree nodes.
3. If result.size() < V → cycle exists.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** None — same asymptotic as DFS approach but with built-in cycle detection.

> **Key Insight for Improvement:** Kahn's naturally detects cycles. DFS approach needs separate cycle check.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Cycle Detection |
|----------|------|-------|----------------|
| Kahn's BFS | O(V+E) | O(V) | Yes |

**Key Insights:**
1. **In-degree 0 = no dependencies:** Safe to process first
2. **Cycle detection:** If not all nodes processed → nodes in cycle have permanent in-degree > 0
3. **BFS gives level-by-level:** Can compute "distance" in dependency chain

<br><br>

---

```code```
