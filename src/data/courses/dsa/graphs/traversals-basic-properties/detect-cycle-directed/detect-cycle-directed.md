Detect if a directed graph contains a cycle.

<br>

> Input: n=4, edges=[[0,1],[1,2],[2,0],[2,3]]
> Output: true (cycle: 0→1→2→0)
> **Key insight:** DFS with three states: WHITE (unvisited), GRAY (in current DFS path), BLACK (fully processed). Back edge to GRAY node = cycle. Or use Kahn's: if topo sort doesn't include all nodes → cycle.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`

<br>

---

## Solution 1: DFS with Three Colors (Optimal)

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(V + E)
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Kahn's Algorithm (BFS)

**Algorithm:** Count in-degrees. Queue nodes with in-degree 0. Process: decrement neighbors' in-degrees. If any reach 0 → enqueue. If processed < V → cycle.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Method |
|----------|------|-------|--------|
| DFS 3-Color | O(V+E) | O(V) | Back edge to gray = cycle |
| Kahn's BFS | O(V+E) | O(V) | processed < V = cycle |

**Key Insights:**
1. **Directed vs undirected:** Parent check doesn't work for directed — need color states
2. **Gray = in current path:** Back edge to gray means we've found a cycle in current DFS path
3. **Kahn's:** If topo sort can't process all nodes, remaining nodes form cycle(s)

<br><br>

---

```code```
