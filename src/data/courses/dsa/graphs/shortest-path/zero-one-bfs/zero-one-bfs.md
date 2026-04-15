Find shortest path in a graph where edge weights are only 0 or 1. More efficient than Dijkstra for this special case.

<br>

> Input: graph with edges of weight 0 or 1, source=0
> Output: shortest distances from source
> **Key insight:** Use a deque instead of priority queue. Weight-0 edges: push to FRONT (same distance). Weight-1 edges: push to BACK (distance + 1). This gives O(V+E) without log factor.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`, edge weights ∈ {0, 1}

<br>

---

## All Possible Edge Cases
1. **All weights 0:** all same distance
2. **All weights 1:** standard BFS
3. **Mix of 0 and 1 weights**

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
> Use 0-1 BFS with Deque (Optimal) for O(V + E) time.

<br>

---

## Solution 2: 0-1 BFS with Deque (Optimal)

**Algorithm:** Deque replaces priority queue. Process front. For weight-0 neighbors: push front (same cost). For weight-1 neighbors: push back (cost + 1).

### Time Complexity: O(V + E)
**Why?** Each node processed once. Deque operations O(1). No log factor!

**Detailed breakdown:** V=100,000, E=200,000 → ~300,000 operations (vs Dijkstra's 3.4M)

### Space Complexity: O(V)

> **Drawback:** Only works when weights are 0 or 1. Not general-purpose.

> **Key Insight for Improvement:** Generalization: for weights 0..K, use K+1 buckets (dial's algorithm). 0-1 BFS is the K=1 special case.

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Weights | Why |
|-----------|------|---------|-----|
| BFS | O(V+E) | Unweighted | Queue |
| 0-1 BFS | O(V+E) | {0, 1} | Deque |
| Dijkstra | O((V+E)logV) | Non-negative | Min-heap |

**Key Insights:**
1. **Deque = sorted:** Front has smallest distance, back has largest (by at most 1)
2. **Weight 0 → front:** Doesn't increase distance — same priority as current
3. **Weight 1 → back:** Increases distance by 1 — process later
4. **Applications:** Grid problems where some moves are free

<br><br>

---

```code```
