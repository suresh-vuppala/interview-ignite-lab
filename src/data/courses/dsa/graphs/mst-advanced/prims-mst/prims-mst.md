Find the MST using Prim's algorithm. Grows the MST one vertex at a time from a starting node.

<br>

> Input: n=4, weighted adjacency list, start=0
> Output: MST with minimum total weight
> **Key insight:** Greedy: maintain a min-heap of edges crossing the cut (MST vs non-MST). Always pick the cheapest crossing edge. Add the new vertex and its edges to the heap.

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
> Use Min-Heap Prim's (Optimal) for O((V + E) log V) time.

<br>

---

## Solution 2: Min-Heap Prim's (Optimal)

**Algorithm:**
1. Start from any node. Push all its edges to min-heap.
2. Extract min-weight edge. If destination not in MST → add it, push its edges.
3. Repeat until V-1 edges added.

### Time Complexity: O((V + E) log V)
**Why?** Each edge pushed/popped from heap at most once. Each operation: O(log V).

**Detailed breakdown:** V=100,000, E=200,000 → ~200,000 × 17 ≈ 3.4M heap operations

### Space Complexity: O(V + E)

> **Drawback:** Slightly more complex than Kruskal's. Better for dense graphs.

> **Key Insight for Improvement:** For dense graphs (E ≈ V²), Prim's O(V² log V) can be better than Kruskal's O(E log E) = O(V² log V²).

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Best For |
|-----------|------|----------|
| Prim's (heap) | O((V+E)logV) | Dense graphs |
| Kruskal's | O(E log E) | Sparse graphs |

**Key Insights:**
1. **Grows from one vertex:** Unlike Kruskal's which processes globally
2. **Min-heap of crossing edges:** Always pick cheapest edge to add a new vertex
3. **Skip already-included:** If popped vertex already in MST → skip

<br><br>

---

```code```
