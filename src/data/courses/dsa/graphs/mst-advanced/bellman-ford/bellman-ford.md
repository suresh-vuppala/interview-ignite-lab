Find shortest paths from a source vertex, handling negative edge weights. Detect negative-weight cycles.

<br>

> Input: n=5, edges with negative weights, source=0
> Output: shortest distances (or "negative cycle detected")
> **Key insight:** Relax ALL edges V-1 times. If any edge can still be relaxed after V-1 iterations → negative cycle exists.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`, edges may have negative weights

<br>

---

## All Possible Edge Cases
1. **Negative weight cycle:** no shortest path exists → detect and report
2. **No path to target:** distance = ∞
3. **All positive weights:** Dijkstra would be faster
4. **Single node**
5. **Parallel edges with different weights**

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
> Use V-1 Iterations + Cycle Check (Optimal) for O(V × E) time.

<br>

---

## Solution 2: V-1 Iterations + Cycle Check (Optimal)

**Algorithm:**
1. dist[source] = 0, all others = ∞
2. Repeat V-1 times: for each edge (u,v,w): if dist[u]+w < dist[v] → dist[v] = dist[u]+w
3. One more pass: if any edge can be relaxed → negative cycle

### Time Complexity: O(V × E)
**Why?** V-1 iterations × E edges each.

**Detailed breakdown:** V=1000, E=5000 → 999 × 5000 = ~5M operations

### Space Complexity: O(V)

> **Drawback:** O(V×E) is slower than Dijkstra's O((V+E)logV) for non-negative weights.

> **Key Insight for Improvement:** Use Bellman-Ford ONLY when negative weights are possible. Otherwise Dijkstra is faster. SPFA (Shortest Path Faster Algorithm) is a practical optimization.

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Negative Weights | Cycle Detection |
|-----------|------|-----------------|----------------|
| Dijkstra | O((V+E)logV) | No | No |
| Bellman-Ford | O(V×E) | Yes | Yes |

**Key Insights:**
1. **V-1 iterations:** Longest shortest path has at most V-1 edges
2. **V-th iteration test:** If distance still decreases → negative cycle reachable
3. **Used in:** Cheapest flights (limited iterations), currency arbitrage detection

<br><br>

---

```code```
