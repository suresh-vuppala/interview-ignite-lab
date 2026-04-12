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

## Solution: V-1 Iterations + Cycle Check (Optimal)

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
