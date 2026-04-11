Detect cycle in undirected graph using Union-Find.

<br>

---

## Solution 1: DSU Cycle Detection

For each edge (u, v): if find(u) == find(v) → cycle! Otherwise union(u, v).

### Time: O(E × α(V)) ≈ O(E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DSU | O(E) | O(V) | Same component = cycle |

<br>
<br>

---

```code```
