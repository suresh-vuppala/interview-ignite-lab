Topological ordering of DAG using DFS.

<br>

---

## Solution 1: DFS + Stack

**Intuition:** DFS postorder gives reverse topological order. Push to stack after all descendants processed.

**Algorithm:**
1. For each unvisited node: DFS
2. After processing all neighbors → push to stack
3. Pop stack → topological order

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: Kahn's BFS (Alternative)

See topological-sort-kahns.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Stack | O(V+E) | O(V) | Postorder gives reverse topo |
| Kahn's BFS | O(V+E) | O(V) | In-degree based |

<br>
<br>

---

```code```
