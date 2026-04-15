Build an adjacency list representation of a graph from a list of edges.

<br>

> Input: n=5, edges=[[0,1],[0,4],[1,2],[1,3],[1,4],[2,3],[3,4]]
> Output: {0:[1,4], 1:[0,2,3,4], 2:[1,3], 3:[1,2,4], 4:[0,1,3]}
> **Key insight:** Adjacency list: map each node to its list of neighbors. For undirected graphs, add both directions. O(V+E) space.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`, `0 ≤ E ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Empty graph:** no edges
2. **Self-loops**
3. **Parallel edges between same pair
4. **Dense vs sparse graph**

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
> Use Adjacency List (Optimal) for O(V + E) time.

<br>

---

## Solution 2: Adjacency List (Optimal)

**Algorithm:** For each edge (u,v): adj[u].push(v). For undirected: also adj[v].push(u).

### Time Complexity: O(V + E)
**Why?** Initialize V lists, process E edges.

**Detailed breakdown:** V=100,000, E=100,000 → 300,000 operations

### Space Complexity: O(V + E)

> **Drawback:** None for adjacency list. Adjacency matrix uses O(V²) space — only efficient for dense graphs.

> **Key Insight for Improvement:** Adjacency list is standard for sparse graphs (most interview problems). Matrix is better when V is small and you need O(1) edge lookup.

<br>

---

## Complexity Progression Summary

| Representation | Space | Edge Lookup | Add Edge | Use When |
|----------------|-------|-------------|----------|----------|
| Adj List | O(V+E) | O(degree) | O(1) | Sparse graphs (E << V²) |
| Adj Matrix | O(V²) | O(1) | O(1) | Dense graphs, small V |
| Edge List | O(E) | O(E) | O(1) | Union-Find algorithms |

**Key Insights:**
1. **Undirected = two entries per edge:** adj[u].push(v) AND adj[v].push(u)
2. **Directed = one entry:** Only adj[u].push(v)
3. **Foundation:** All graph algorithms start with building adjacency list

<br><br>

---

```code```
