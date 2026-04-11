Clone a connected undirected graph — deep copy all nodes and edges.

<br>

---

## Solution 1: DFS + HashMap (Standard)

**Intuition:** Use hashmap old→new to track cloned nodes. DFS: if already cloned, return clone. Otherwise create clone, recurse on neighbors.

### Time: O(V + E) | Space: O(V) — hashmap + recursion

<br>

---

## Solution 2: BFS + HashMap

Same logic with queue instead of recursion.

### Time: O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Map | O(V+E) | O(V) | Recursive cloning |
| BFS + Map | O(V+E) | O(V) | Iterative cloning |

<br>
<br>

---

```code```
