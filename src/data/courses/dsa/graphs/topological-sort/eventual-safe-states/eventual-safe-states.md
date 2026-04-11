Find all nodes that eventually reach a terminal node (no outgoing edges).

<br>

---

## Solution 1: DFS 3-Color

Nodes in cycles are unsafe. Terminal nodes and nodes leading only to safe nodes are safe. Use 3-color DFS to detect cycle membership.

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: Reverse Graph + Kahn's

Reverse edges. Terminal nodes have in-degree 0 in reverse. Kahn's from terminals marks all safe nodes.

### Time: O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS 3-Color | O(V+E) | O(V) | Cycle = unsafe |
| Reverse Kahn's | O(V+E) | O(V) | BFS from terminals |

<br>
<br>

---

```code```
