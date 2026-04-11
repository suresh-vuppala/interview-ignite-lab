Detect cycle in an undirected graph.

<br>

---

## Solution 1: DFS with Parent Tracking

If neighbor is visited AND not parent → cycle found.

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: Union-Find (DSU)

For each edge (u,v): if find(u) == find(v) → cycle. Else union(u,v).

### Time: O(V + E × α(V)) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Parent | O(V+E) | O(V) | Track parent in DFS |
| DSU | O(V+E) | O(V) | Union-find cycle detection |

<br>
<br>

---

```code```
