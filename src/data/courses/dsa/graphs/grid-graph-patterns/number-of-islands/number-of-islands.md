Given a 2D grid of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and connected 4-directionally.

<br>

> Input: grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
> Output: 3
> **Key insight:** Same as counting connected components — but on a grid. DFS/BFS from each unvisited '1', sinking the island (mark as '0'). Each launch = one island.

<br>

---

## Constraints
- `1 ≤ m, n ≤ 300`

<br>

---

## Solution 1: BFS flood fill

**Intuition:**
The most straightforward approach — bfs works equally well.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(M×N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> BFS works equally well. DFS is simpler to implement recursively.

> **Key Insight for Improvement:**
> Use DFS + Sink Island (Optimal) for O(M × N) time.

<br>

---

## Solution 2: DFS + Sink Island (Optimal)

**Algorithm:** For each cell with '1': count++, DFS to mark entire island as '0' (visited).

### Time Complexity: O(M × N)
**Why?** Each cell visited at most once.

**Detailed breakdown:** 300×300 = 90,000 cells

### Space Complexity: O(M × N) worst case for DFS recursion on large island

> **Drawback:** DFS recursion depth can be O(M×N) for snake-shaped islands. BFS avoids deep recursion.

> **Key Insight for Improvement:** BFS alternative uses O(min(M,N)) queue space. Union-Find also works in O(M×N×α).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS Sink | O(M×N) | O(M×N) | Mark visited by overwriting grid |
| BFS | O(M×N) | O(min(M,N)) | Queue-based, less stack depth |

**Key Insights:**
1. **Grid = implicit graph:** Each cell is a node, adjacent cells are edges
2. **Sink to avoid visited array:** Overwrite '1'→'0' instead of separate visited
3. **FAANG top-5:** Most frequently asked graph problem

<br><br>

---

```code```
