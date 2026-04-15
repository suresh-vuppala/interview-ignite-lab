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

## All Possible Edge Cases
1. **Self-loop:** cycle of length 1
2. **Parallel edges:** multiple edges between same pair
3. **Tree (no cycle):** V-1 edges, connected
4. **Disconnected with cycle in one component**
5. **Single node:** no cycle possible

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use DFS with Parent Tracking (Optimal) for O(V + E) time.

<br>

---

## Solution 2: DFS with Parent Tracking (Optimal)

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
