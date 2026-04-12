Find the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.

<br>

> Input: n=5, edges=[[0,1,4],[0,2,1],[2,1,2],[1,3,1],[2,3,5],[3,4,3]], source=0
> Output: dist=[0,3,1,4,7]
> **Key insight:** Greedy: always process the unvisited node with the smallest known distance. Use a min-heap (priority queue) for efficient extraction. Relax neighbors — if shorter path found, update distance.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`, `0 ≤ E ≤ 2×10⁵`
- Non-negative edge weights

<br>

---

## Solution 1: Basic — O(V²) with Array

### Time Complexity: O(V²)

> **Drawback:** Scans all V nodes to find minimum distance each iteration. For sparse graphs, this is wasteful.

> **Key Insight for Improvement:** Use a min-heap (priority queue) to extract minimum in O(log V). Total: O((V+E) log V).

<br>

---

## Solution 2: Min-Heap Priority Queue (Optimal for sparse)

**Algorithm:**
1. dist[source] = 0, all others = ∞. Min-heap with (0, source).
2. While heap not empty: extract (d, u) with minimum distance.
   - If d > dist[u] → skip (stale entry)
   - For each neighbor v with weight w: if dist[u]+w < dist[v] → update dist[v], push (dist[v], v)

### Time Complexity: O((V + E) log V)
**Why?** At most E relaxations, each push/pop is O(log V). Total: O(E log V).

**Detailed breakdown:** V=100,000, E=200,000 → ~200,000 × 17 ≈ 3.4M operations

### Space Complexity: O(V + E)

**Example walkthrough:**
```
Source=0, edges: 0→1(4), 0→2(1), 2→1(2), 1→3(1), 2→3(5), 3→4(3)

Heap: [(0,0)]
Extract (0,0): relax 1→dist[1]=4, 2→dist[2]=1. Heap: [(1,2),(4,1)]
Extract (1,2): relax 1→1+2=3<4→dist[1]=3, 3→1+5=6. Heap: [(3,1),(4,1),(6,3)]
Extract (3,1): relax 3→3+1=4<6→dist[3]=4. Heap: [(4,1),(4,3),(6,3)]
Extract (4,3): relax 4→4+3=7. Heap: [(4,1),(6,3),(7,4)]
... remaining are stale

dist = [0, 3, 1, 4, 7] ✓
```

> **Drawback:** Doesn't work with negative edge weights — greedy assumption fails.

> **Key Insight for Improvement:** For negative weights, use Bellman-Ford O(V×E). For all-pairs, use Floyd-Warshall O(V³).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Use Case |
|----------|------|-------|----------|
| Array scan | O(V²) | O(V) | Dense graphs |
| Min-Heap | O((V+E)logV) | O(V+E) | Sparse graphs (most interviews) |

**Key Insights:**
1. **Greedy:** Always process closest unvisited node — guaranteed optimal for non-negative weights
2. **Lazy deletion:** Push new entries instead of decreasing key — skip stale entries
3. **Cannot handle negative weights:** Greedy assumption breaks
4. **FAANG critical:** Foundation for network-delay-time, cheapest-flights

<br><br>

---

```code```
