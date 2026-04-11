## Building Graph Representations

**Adjacency List (Most Common):**
```
vector<vector<int>> adj(n);
for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}
```
Space: O(V + E) | Edge lookup: O(degree)

**Adjacency Matrix:**
```
vector<vector<bool>> mat(n, vector<bool>(n, false));
```
Space: O(V²) | Edge lookup: O(1) | Best for dense graphs

**Edge List:** Simply store edges. Best for Kruskal's MST.

<br>

---

## Complexity Comparison

| Representation | Space | Add Edge | Check Edge | Iterate Neighbors |
|---------------|-------|----------|-----------|-------------------|
| Adj List | O(V+E) | O(1) | O(degree) | O(degree) |
| Adj Matrix | O(V²) | O(1) | O(1) | O(V) |
| Edge List | O(E) | O(1) | O(E) | O(E) |

<br>
<br>

---

```code```
