Build an adjacency list for a weighted graph. Each edge has a weight/cost.

<br>

> Input: n=4, edges=[[0,1,5],[0,2,3],[1,2,1],[2,3,7]]
> Output: {0:[(1,5),(2,3)], 1:[(0,5),(2,1)], 2:[(0,3),(1,1),(3,7)], 3:[(2,7)]}
> **Key insight:** Store (neighbor, weight) pairs instead of just neighbor. Same adjacency list but with weight attached.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Zero-weight edges**
2. **Negative weight edges**
3. **Parallel edges with different weights**

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
> Use Adjacency List with Weights (Optimal) for O(V + E) time.

<br>

---

## Solution 2: Adjacency List with Weights (Optimal)

**Algorithm:** For each edge (u,v,w): adj[u].push({v,w}). For undirected: also adj[v].push({u,w}).

### Time Complexity: O(V + E)
### Space Complexity: O(V + E)

> **Drawback:** None — standard for weighted graphs.

> **Key Insight for Improvement:** Foundation for Dijkstra, Bellman-Ford, Kruskal, Prim. Always store (neighbor, weight) pairs.

<br>

---

## Complexity Progression Summary

| Representation | Storage per Edge |
|----------------|-----------------|
| Unweighted | neighbor only |
| Weighted | (neighbor, weight) pair |

**Key Insights:**
1. **Pair storage:** adj[u] = list of (v, weight)
2. **Dijkstra needs this:** Priority queue uses weights for relaxation
3. **Negative weights:** Bellman-Ford handles; Dijkstra does not

<br><br>

---

```code```
