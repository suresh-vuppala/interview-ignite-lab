## Finding Node Degrees

**Undirected:** degree(v) = number of neighbors = adj[v].size()
**Directed:** in-degree = count of edges pointing TO v. out-degree = count of edges FROM v.

**Algorithm (Directed):**
```
for each edge (u, v):
    outDegree[u]++
    inDegree[v]++
```

### Time: O(V + E) | Space: O(V)

<br>
<br>

---

```code```
