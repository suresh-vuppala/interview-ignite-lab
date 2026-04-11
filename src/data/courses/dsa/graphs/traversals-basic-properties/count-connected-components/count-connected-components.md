Count the number of connected components in an undirected graph.

<br>

> Input: n=5, edges=[[0,1],[1,2],[3,4]]
> Output: 2 (components: {0,1,2} and {3,4})
> **Key insight:** Run BFS/DFS from each unvisited node. Each launch = one new component.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: DFS from Each Unvisited Node (Optimal)

**Algorithm:** For each node 0..n-1: if not visited → count++, DFS/BFS to visit entire component.

### Time Complexity: O(V + E)
**Why?** Each node and edge visited once across all DFS calls.

**Detailed breakdown:** V=100,000, E=100,000 → 300,000 operations total

### Space Complexity: O(V)

> **Drawback:** None — O(V+E) is optimal.

> **Key Insight for Improvement:** Union-Find (DSU) also counts components in O(V+E×α(V)) ≈ O(V+E). Both are optimal.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS/BFS | O(V+E) | O(V) |
| Union-Find | O(V+E·α) | O(V) |

**Key Insights:**
1. **Each DFS launch = new component**
2. **Total work = O(V+E)** across all launches (not per launch)
3. **Foundation for:** Number of Islands (grid version), Number of Provinces

<br><br>

---

```code```
