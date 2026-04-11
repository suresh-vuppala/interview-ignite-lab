## Graphs — Connected Components, Paths & Cycles

A graph models relationships between objects (nodes connected by edges). Graphs are the **most versatile data structure** — trees, linked lists, and grids are all special cases of graphs.

<br>

## Why Graphs Are Critical

- **~15% of FAANG interviews** involve graph problems
- **Google's favorite topic** — More graph questions than any other company
- **Versatile patterns** — BFS, DFS, topological sort, shortest path, MST, DSU

<br>

## Graph Representations

| Representation | Space | Edge Lookup | Best For |
|---------------|-------|-------------|----------|
| Adjacency List | O(V + E) | O(degree) | Sparse graphs |
| Adjacency Matrix | O(V²) | O(1) | Dense graphs |
| Edge List | O(E) | O(E) | Kruskal's MST |

<br>

## Module Roadmap

1. **Fundamentals** — Build graph, BFS, DFS, connected components
2. **Cycle detection** — Undirected (DFS/DSU), directed (coloring)
3. **Grid patterns** — Islands, flood fill, rotting oranges
4. **Topological sort** — Course schedule, alien dictionary
5. **Shortest path** — Dijkstra, Bellman-Ford, 0-1 BFS
6. **MST & DSU** — Kruskal's, Prim's, union-find

<br>
