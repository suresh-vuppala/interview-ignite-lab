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
> Use Count from Edge List (Optimal) for O(V + E) time.

<br>

---

## Solution 2: Count from Edge List (Optimal)

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
