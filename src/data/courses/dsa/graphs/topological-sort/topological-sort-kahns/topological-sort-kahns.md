Topological sort using Kahn's algorithm (BFS, in-degree based).

<br>

---

## Solution 1: Kahn's Algorithm (BFS)

**Intuition:** Repeatedly remove nodes with in-degree 0. They have no dependencies.

**Algorithm:**
1. Compute in-degree for all nodes
2. Enqueue all nodes with in-degree 0
3. While queue not empty:
   - Dequeue node → add to result
   - For each neighbor: decrement in-degree. If 0 → enqueue
4. If result.size() < V → cycle exists

### Time: O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Kahn's BFS | O(V+E) | O(V) | In-degree removal, detects cycles |

<br>
<br>

---

```code```
