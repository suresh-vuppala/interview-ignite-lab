Find the edge that, when removed, makes the graph a valid tree. The graph has exactly one extra edge.

<br>

> Input: edges=[[1,2],[1,3],[2,3]]
> Output: [2,3]
> **Key insight:** Process edges in order with Union-Find. The first edge where both endpoints are already connected = the redundant edge (creates the cycle).

<br>

---

## Constraints
- Tree has N nodes, N edges (one extra)

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
> Use DSU — Find First Cycle-Creating Edge (Optimal) for O(N × α(N)) ≈ O(N) time.

<br>

---

## Solution 2: DSU — Find First Cycle-Creating Edge (Optimal)

**Algorithm:** Process edges sequentially. For each edge: if find(u)==find(v) → this is the redundant edge. Return it.

### Time Complexity: O(N × α(N)) ≈ O(N)
### Space Complexity: O(N)

> **Drawback:** None.

> **Key Insight for Improvement:** If multiple redundant edges possible, return the LAST one in the input (per LeetCode spec).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DSU | O(N·α) | O(N) |

**Key Insights:**
1. **Tree + 1 edge = exactly one cycle**
2. **DSU naturally finds it:** First edge connecting already-connected nodes
3. **Last such edge:** If problem asks for last redundant edge, track it instead of returning first

<br><br>

---

```code```
