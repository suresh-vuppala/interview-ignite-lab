Find the shortest path between two nodes in a weighted graph. Return the path and its total weight.

<br>

> Input: n=5, source=0, target=4, edges with weights
> Output: path=[0,2,1,3,4], weight=7
> **Key insight:** Dijkstra + parent tracking. During relaxation, record parent[v] = u. After Dijkstra, backtrack from target using parent pointers to reconstruct path.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`, non-negative weights

<br>

---

## All Possible Edge Cases
1. **Unreachable node:** distance = ∞
2. **Source = destination:** 0
3. **Multiple shortest paths of same length**

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
> Use Dijkstra + Parent Backtracking (Optimal) for O((V+E) log V) time.

<br>

---

## Solution 2: Dijkstra + Parent Backtracking (Optimal)

**Algorithm:** Run Dijkstra. Additionally, parent[v] = u when dist[v] is updated. After finding dist[target], reconstruct path by following parent pointers from target to source.

### Time Complexity: O((V+E) log V)
**Why?** Dijkstra dominates. Path reconstruction: O(V).

**Detailed breakdown:** Same as Dijkstra + O(V) backtracking

### Space Complexity: O(V + E)

> **Drawback:** None — standard Dijkstra extension.

> **Key Insight for Improvement:** For unweighted graphs, BFS is simpler and gives O(V+E) without a heap.

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Weights | Path Recovery |
|-----------|------|---------|--------------|
| BFS | O(V+E) | Unweighted only | Parent array |
| Dijkstra | O((V+E)logV) | Non-negative | Parent array |
| Bellman-Ford | O(V×E) | Any (incl. negative) | Parent array |

**Key Insights:**
1. **Parent tracking:** parent[v] = u when relaxing edge u→v
2. **Backtrack:** target → parent[target] → ... → source, then reverse
3. **Foundation for:** All shortest path problems that need the actual path

<br><br>

---

```code```
