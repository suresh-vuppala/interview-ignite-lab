Detect if an undirected graph contains a cycle.

<br>

> Input: n=4, edges=[[0,1],[1,2],[2,3],[3,1]]
> Output: true (cycle: 1→2→3→1)
> **Key insight:** DFS with parent tracking. If we visit a neighbor that's already visited AND it's not our parent → cycle found. BFS alternative: same parent check.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution: DFS with Parent Tracking (Optimal)

**Algorithm:** DFS(node, parent). For each neighbor: if visited AND ≠ parent → cycle. If not visited → recurse.

### Time Complexity: O(V + E)
**Why?** Standard DFS traversal.

**Detailed breakdown:** V=100,000, E=100,000 → ~300,000 operations

### Space Complexity: O(V)

> **Drawback:** Need to handle disconnected graphs — run DFS from all unvisited nodes.

> **Key Insight for Improvement:** Union-Find alternative: for each edge, if both endpoints already in same set → cycle. O(E×α(V)).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS + Parent | O(V+E) | O(V) |
| Union-Find | O(E·α) | O(V) |

**Key Insights:**
1. **Parent check critical:** In undirected graphs, the edge back to parent is NOT a cycle
2. **visited + ≠ parent = cycle:** The defining condition
3. **Disconnected:** Must check all components

<br><br>

---

```code```
