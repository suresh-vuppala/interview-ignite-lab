Check if a graph is bipartite — can nodes be colored with 2 colors such that no two adjacent nodes share the same color?

<br>

> Input: n=4, adj=[[1,3],[0,2],[1,3],[0,2]]
> Output: true (color: 0→A, 1→B, 2→A, 3→B)
> **Key insight:** BFS/DFS coloring. Assign color to start node. Neighbors get opposite color. If a neighbor already has the same color → not bipartite. Equivalent to checking for odd-length cycles.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Odd-length cycle:** NOT bipartite
2. **Even-length cycle:** bipartite
3. **Tree:** always bipartite
4. **Disconnected graph:** check each component
5. **Single node:** bipartite (trivially)
6. **Self-loop:** NOT bipartite

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
> Use BFS 2-Coloring (Optimal) for O(V + E) time.

<br>

---

## Solution 2: BFS 2-Coloring (Optimal)

**Algorithm:** BFS from each unvisited node. Color start with 0. Neighbors get 1-color[node]. If neighbor already colored same → false.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** None — O(V+E) is optimal.

> **Key Insight for Improvement:** Bipartite ↔ no odd-length cycles. 2-coloring is the standard check.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS 2-Color | O(V+E) | O(V) |
| DFS 2-Color | O(V+E) | O(V) |

**Key Insights:**
1. **2-colorable = bipartite = no odd cycles**
2. **Color assignment:** Alternate 0/1 at each BFS level
3. **Handle disconnected:** Check all components

<br><br>

---

```code```
