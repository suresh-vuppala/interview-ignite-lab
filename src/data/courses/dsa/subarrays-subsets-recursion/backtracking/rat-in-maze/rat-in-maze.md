Find all paths from top-left to bottom-right in a maze where rat can move through cells with value 1.

<br>

> Input:
> maze = [[1,0,0,0],
>         [1,1,0,1],
>         [0,1,0,0],
>         [1,1,1,1]]

> Output:
> ["DDRDRR", "DRDDRR"]

> Explanation:
> Two paths exist from (0,0) to (3,3)
> D=Down, R=Right, U=Up, L=Left
> 
> **Key insight:** DFS with backtracking - try all 4 directions, mark visited, backtrack if dead end.

<br>

---

## Solution: Backtracking with DFS

**Intuition:**
Start from (0,0), try moving in all 4 directions (Down, Right, Up, Left).
Mark cells as visited to avoid cycles.
If reach destination, record path.
If stuck, backtrack by unmarking cell and trying different direction.

**Movement Directions:**
```cpp
Directions: D, L, R, U (alphabetical order for lexicographic paths)
Down:  row+1, col
Left:  row, col-1
Right: row, col+1
Up:    row-1, col
```

**Algorithm:**
1. Start at (0,0) with empty path
2. Base case: if reached (n-1, m-1), add path to result
3. Mark current cell as visited
4. Try all 4 directions:
   - Check if next cell is valid (in bounds, value=1, not visited)
   - If valid, append direction to path and recurse
   - After recursion, remove last direction (backtrack)
5. Unmark current cell as visited (backtrack)

**Example Walkthrough:**
```
maze = [[1,0,0,0],
        [1,1,0,1],
        [0,1,0,0],
        [1,1,1,1]]

Start at (0,0), path=""

Try D: (1,0) valid, path="D"
  Try D: (2,0)=0 invalid
  Try L: out of bounds
  Try R: (1,1) valid, path="DR"
    Try D: (2,1) valid, path="DRD"
      Try D: (3,1) valid, path="DRDD"
        Try D: out of bounds
        Try L: (3,0) valid, path="DRDDL"
          Try D: out of bounds
          Try L: out of bounds
          Try R: (3,1) visited
          Try U: (2,1) visited
          Dead end, backtrack
        Try R: (3,2) valid, path="DRDDR"
          Try D: out of bounds
          Try L: (3,1) visited
          Try R: (3,3) valid, path="DRDDRR" → destination! ✓
          
Continue exploring other paths...
Path 2: "DDRDRR" ✓

Result: ["DDRDRR", "DRDDRR"]
```

**Visual Path Representation:**
```
Path 1: DDRDRR
S . . .     S . . .     S . . .     S . . .
↓ . . .     ↓ . . .     ↓ . . .     ↓ . . .
. . . .     ↓ . . .     ↓ . . .     ↓ . . .
. . . .     . . . .     . → . .     . → → E

Path 2: DRDDRR
S . . .     S . . .     S . . .     S . . .
↓ . . .     ↓ → . .     ↓ → . .     ↓ → . .
. . . .     . ↓ . .     . ↓ . .     . ↓ . .
. . . .     . . . .     . ↓ → .     . ↓ → E
```

### Time Complexity: O(4^(N×M))
**Why?**
- At each cell, try up to 4 directions
- Maximum path length: N×M cells
- Worst case: 4^(N×M) paths explored
- Pruning reduces actual complexity significantly

**Detailed breakdown:**
- Each cell: 4 choices (D, L, R, U)
- Path length: up to N×M
- Total branches: 4 × 4 × 4 × ... (N×M times)
- Visited tracking prunes many branches

### Space Complexity: O(N×M)
**Why?**
- Recursion stack: O(N×M) for longest path
- Visited array: O(N×M)
- Current path string: O(N×M)
- Total: O(N×M)

<br>

---

## Optimizations

**1. Lexicographic Order:**
Try directions in alphabetical order (D, L, R, U) to get sorted output.

**2. Early Termination:**
If only one path needed, return immediately after finding first.

**3. Direction Arrays:**
```cpp
int dx[] = {1, 0, 0, -1};  // D, L, R, U
int dy[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};

for (int i = 0; i < 4; i++) {
    int newX = x + dx[i];
    int newY = y + dy[i];
    // check and recurse
}
```

**4. In-place Visited Marking:**
Instead of separate visited array, mark maze[i][j] = 0 when visiting, restore to 1 when backtracking.

<br>

---

## Variations

**1. Count Paths Only:**
Don't store path strings, just count.
**Time:** O(4^(N×M)), **Space:** O(N×M)

**2. Shortest Path:**
Use BFS instead of DFS.
**Time:** O(N×M), **Space:** O(N×M)

**3. With Obstacles:**
Already handled - cells with 0 are obstacles.

**4. Multiple Start/End Points:**
Try all combinations of start and end.

<br>

---

## Key Insights

1. **Backtracking Pattern:** Try → Recurse → Undo
2. **Visited Tracking:** Essential to avoid infinite loops
3. **4 Directions:** Must check all possible moves
4. **Path Building:** Append direction when moving, remove when backtracking

**Common Mistakes:**
- Forgetting to unmark visited cell when backtracking
- Not checking bounds before accessing maze[i][j]
- Not checking if cell is already visited
- Wrong direction order (affects lexicographic output)

<br>

---

## Comparison with Other Approaches

| Approach | Use Case | Time | Space |
|----------|----------|------|-------|
| DFS Backtracking | All paths | O(4^(N×M)) | O(N×M) |
| BFS | Shortest path | O(N×M) | O(N×M) |
| Dijkstra | Weighted maze | O(N×M log(N×M)) | O(N×M) |
| A* | Heuristic search | O(N×M) | O(N×M) |

<br>

---

## Edge Cases

1. **No path exists:** Return empty array
2. **Start or end blocked:** Return empty array
3. **Single cell (1×1):** Return [""] if maze[0][0]=1
4. **All cells accessible:** Many paths possible
5. **Narrow corridors:** Fewer paths, faster execution

<br>

---

## Applications

1. **Robotics:** Path planning in grid environments
2. **Game Development:** NPC pathfinding, maze generation
3. **Network Routing:** Finding all routes between nodes
4. **Puzzle Solving:** Maze puzzles, escape rooms
5. **Circuit Design:** Routing connections on PCB

<br>
<br>

---

```code```
