Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.

<br>

---

## Constraints

- `0 ≤ number of nodes ≤ 100`
- `1 ≤ Node.val ≤ 100`
- `No duplicate values`
- `No self-loops`

<br>

---

## All Possible Edge Cases

1. **Empty graph:** Return null
2. **Single node, no neighbors:** Return single cloned node
3. **Fully connected graph:** All nodes reference each other
4. **Linear graph (chain):** Each node has one neighbor
5. **Cycle in graph:** Must handle visited to avoid infinite loop

<br>

---

```code```
