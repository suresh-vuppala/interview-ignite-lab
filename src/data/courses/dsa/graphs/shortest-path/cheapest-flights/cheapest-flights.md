Find the cheapest price from src to dst with at most k stops. Return -1 if no such route.

<br>

> Input: n=4, flights=[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src=0, dst=3, k=1
> Output: 700 (route: 0→1→3, cost=100+600=700)
> **Key insight:** Modified Dijkstra or Bellman-Ford with stop limit. Bellman-Ford: run exactly k+1 iterations (k+1 edges = k stops). Each iteration relaxes all edges using previous iteration's distances.

<br>

---

## Constraints
- `1 ≤ n ≤ 100`, `0 ≤ k < n`

<br>

---

## All Possible Edge Cases
1. **No path within K stops:** return -1
2. **Direct flight exists**
3. **K = 0:** only direct flights
4. **Cheaper path needs more stops**

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
> Use Bellman-Ford with K+1 Iterations (Optimal) for O(K × E) time.

<br>

---

## Solution 2: Bellman-Ford with K+1 Iterations (Optimal)

**Algorithm:** Run Bellman-Ford for exactly k+1 rounds. In each round, relax all edges using the PREVIOUS round's distances (copy before relaxing).

### Time Complexity: O(K × E)
**Why?** K+1 iterations × E edges per iteration.

**Detailed breakdown:** K=100, E=5000 → 500,000 relaxations

### Space Complexity: O(V)

> **Drawback:** O(K×E) can be slow if K and E are large. Modified Dijkstra with (cost, node, stops) tuples is an alternative.

> **Key Insight for Improvement:** Modified Dijkstra: push (cost, node, remainingStops) to heap. When stops exhausted, don't explore further. May visit same node multiple times with different stop counts.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Constraint |
|----------|------|-------|----------------|
| Bellman-Ford K+1 | O(K×E) | O(V) | Exact iteration count |
| Modified Dijkstra | O(E×K×logV) | O(V×K) | Track stops in state |

**Key Insights:**
1. **Stop limit = edge limit:** k stops = k+1 edges maximum
2. **Copy before relaxing:** Use previous round's distances (not current — prevents using too many edges)
3. **Modified Dijkstra:** State = (cost, node, stops_remaining)

<br><br>

---

```code```
