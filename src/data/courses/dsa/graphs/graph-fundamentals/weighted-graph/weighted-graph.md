## Weighted Graph Representation

**Adjacency List with Weights:**
```cpp
vector<vector<pair<int,int>>> adj(n); // {neighbor, weight}
adj[u].push_back({v, w});
```

**Edge List with Weights:**
```cpp
vector<tuple<int,int,int>> edges; // {u, v, weight}
```

Used in: Dijkstra (adj list + min-heap), Bellman-Ford (edge list), Kruskal's (sorted edge list).

<br>
<br>

---

```code```
