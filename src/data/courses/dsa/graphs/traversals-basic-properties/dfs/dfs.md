Implement Depth-First Search (DFS) on a graph. Return nodes in DFS order.

<br>

> Input: n=5, adj={0:[1,2], 1:[0,3], 2:[0,4], 3:[1], 4:[2]}, start=0
> Output: [0, 1, 3, 2, 4] (one possible DFS order)
> **Key insight:** Stack-based (or recursive) traversal. Go as deep as possible before backtracking. Explores one branch completely before trying another.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`, `0 ≤ E ≤ 10⁵`

<br>

---

## Solution: Recursive DFS (Optimal)

**Algorithm:**
1. Mark start as visited, process it
2. For each unvisited neighbor: recursively DFS

### Time Complexity: O(V + E)
**Why?** Each vertex visited once. Each edge examined once.

**Detailed breakdown:** V=100,000, E=100,000 → ~300,000 operations

### Space Complexity: O(V)
**Why?** Visited array + recursion stack (O(V) worst case for chain graph).

> **Drawback:** Recursion may cause stack overflow on very deep graphs. Use iterative DFS with explicit stack.

> **Key Insight for Improvement:** Iterative DFS: use a stack instead of recursion. Same O(V+E) time, avoids stack overflow.

<br>

---

## Complexity Progression Summary

| Variant | Time | Space | Notes |
|---------|------|-------|-------|
| Recursive DFS | O(V+E) | O(V) | Clean code, stack overflow risk |
| Iterative DFS | O(V+E) | O(V) | Explicit stack, no overflow |

**Key Insights:**
1. **DFS uses stack (LIFO):** Goes deep first. BFS uses queue (FIFO).
2. **Applications:** Cycle detection, topological sort, connected components, pathfinding
3. **Visited timing:** Mark visited WHEN visiting (not when pushing to stack for iterative)

<br><br>

---

```code```
