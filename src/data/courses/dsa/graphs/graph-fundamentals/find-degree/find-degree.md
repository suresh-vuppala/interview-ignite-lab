Find the degree of each node in a graph. For directed graphs, find in-degree and out-degree.

<br>

> Input: n=4, edges=[[0,1],[0,2],[1,2],[2,3]]
> Output (undirected): [2, 2, 3, 1]
> **Key insight:** Degree = number of edges incident to a node. Undirected: each edge contributes 1 to both endpoints. Directed: out-degree from source, in-degree at destination.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: Count from Edge List (Optimal)

**Algorithm:** For each edge (u,v): degree[u]++, degree[v]++ (undirected). For directed: outDeg[u]++, inDeg[v]++.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** None.

> **Key Insight for Improvement:** In-degree is crucial for Kahn's topological sort (start from nodes with in-degree 0). Degree is used in Euler path/circuit checks.

<br>

---

## Complexity Progression Summary

| Operation | Time | Space |
|-----------|------|-------|
| Count degrees | O(E) | O(V) |

**Key Insights:**
1. **Sum of degrees = 2E** (handshaking lemma for undirected)
2. **In-degree 0 = source** in DAG (topological sort start)
3. **Euler circuit:** All even degrees (undirected)

<br><br>

---

```code```
