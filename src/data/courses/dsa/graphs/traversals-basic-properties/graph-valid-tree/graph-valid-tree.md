Check if edges form a valid tree (connected + no cycles + n-1 edges).

<br>

---

## Solution 1: BFS/DFS — Check connected + n-1 edges

If edges != n-1 → false. If BFS from 0 visits all n nodes → true.

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: Union-Find

Process each edge. If union fails (already connected) → cycle. After all edges, check one component.

### Time: O(V + E × α(V)) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS + edge count | O(V+E) | O(V) | Connected + n-1 edges |
| Union-Find | O(V+E) | O(V) | Cycle detection via DSU |

<br>
<br>

---

```code```
