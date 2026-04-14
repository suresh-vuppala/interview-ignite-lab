Return a topological ordering using Kahn's algorithm (BFS-based). Also detects cycles.

<br>

> Input: n=6, edges=[[5,2],[5,0],[4,0],[4,1],[2,3],[3,1]]
> Output: [4,5,2,0,3,1] (one valid ordering)
> **Key insight:** Start from nodes with in-degree 0 (no dependencies). Process them, decrement neighbors' in-degrees. New in-degree-0 nodes are enqueued. If output < V → cycle.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution 1: DFS-based topological sort

**Intuition:**
The most straightforward approach — dfs with finish-time ordering.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(V+E)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> DFS with finish-time ordering. Kahn's BFS is more intuitive for detecting cycles.

> **Key Insight for Improvement:**
> Use Kahn's BFS (Optimal) for O(V + E) time.

<br>

---

## Solution 2: Kahn's BFS (Optimal)

**Algorithm:**
1. Compute in-degrees. Enqueue all nodes with in-degree 0.
2. While queue: dequeue node → add to result → decrement neighbors' in-degrees → enqueue new zero-in-degree nodes.
3. If result.size() < V → cycle exists.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** None — same asymptotic as DFS approach but with built-in cycle detection.

> **Key Insight for Improvement:** Kahn's naturally detects cycles. DFS approach needs separate cycle check.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Cycle Detection |
|----------|------|-------|----------------|
| Kahn's BFS | O(V+E) | O(V) | Yes |

**Key Insights:**
1. **In-degree 0 = no dependencies:** Safe to process first
2. **Cycle detection:** If not all nodes processed → nodes in cycle have permanent in-degree > 0
3. **BFS gives level-by-level:** Can compute "distance" in dependency chain

<br><br>

---

```code```
