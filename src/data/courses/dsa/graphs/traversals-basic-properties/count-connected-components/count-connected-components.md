Count the number of connected components in an undirected graph.

<br>

---

## Solution 1: DFS/BFS from Each Unvisited Node

For each unvisited node, run DFS/BFS to mark the entire component. Increment count.

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: Union-Find (DSU)

Process each edge with union. Count distinct roots.

### Time: O(V + E × α(V)) ≈ O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS/BFS | O(V+E) | O(V) | Traverse each component |
| DSU | O(V+E) | O(V) | Union-find alternative |

<br>
<br>

---

```code```
