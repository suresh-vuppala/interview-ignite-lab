Detect a cycle in an undirected graph using Union-Find.

<br>

> Input: n=4, edges=[[0,1],[1,2],[2,3],[3,1]]
> Output: true
> **Key insight:** Process edges one by one. Before adding edge (u,v): if find(u)==find(v) → they're already connected → adding this edge creates a cycle.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Tree (V-1 edges):** no cycle
2. **Self-loop:** cycle
3. **Parallel edges between same pair**

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
> Use Union-Find Cycle Check (Optimal) for O(E × α(V)) ≈ O(E) time.

<br>

---

## Solution 2: Union-Find Cycle Check (Optimal)

**Algorithm:** For each edge (u,v): if find(u)==find(v) → cycle. Else union(u,v).

### Time Complexity: O(E × α(V)) ≈ O(E)
### Space Complexity: O(V)

> **Drawback:** None — equivalent to DFS cycle detection.

> **Key Insight for Improvement:** DSU is especially useful when edges are given as a stream (online algorithm). DFS requires the full graph upfront.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS | O(V+E) | O(V) |
| DSU | O(E·α) ≈ O(E) | O(V) |

**Key Insights:**
1. **Same component = cycle:** If u and v already connected before adding edge → cycle
2. **Online algorithm:** Can process edges one at a time
3. **Simpler for edge-list input:** No need to build adjacency list

<br><br>

---

```code```
