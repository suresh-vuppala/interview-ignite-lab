Find the edge that creates a cycle in a tree + 1 edge graph.

<br>

---

## Solution 1: Union-Find (Optimal)

Process edges one by one. The first edge where both endpoints are already in the same component → that's the redundant edge.

### Time: O(n × α(n)) ≈ O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DSU | O(n) | O(n) | First edge connecting same component |

<br>
<br>

---

```code```
