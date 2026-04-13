Find all paths from (0,0) to (N-1,N-1) in a maze with blocked cells.

<br>

> maze=[[1,0,0],[1,1,0],[0,1,1]] → paths using D,L,R,U
>
> **Key insight:** DFS backtracking: try all 4 directions. Mark visited cells. If reach destination, record path. Backtrack to explore all paths.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Same DFS approach

### Time Complexity: O(4^(N²))

> **Drawback:**
> Exponential — must explore all paths.

> **Key Insight for Improvement:**
> DFS with visited matrix. Explore D, L, R, U in lexicographic order. Mark/unmark visited.

<br>

---

## Solution 2: DFS Backtracking (Optimal)

**Intuition:** DFS backtracking: try all 4 directions. Mark visited cells. If reach destination, record path. Backtrack to explore all paths.

**Algorithm:**
1. If at (N-1,N-1): record path
2. For each direction (D,L,R,U):
   - If valid (in bounds, not blocked, not visited):
     - Mark visited, append direction, recurse
     - Unmark visited, remove direction (backtrack)

### Time Complexity: O(4^(N²))
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Start (0,0)→D→(1,0)→D→blocked. Backtrack→R→(1,1)→D→blocked→R→(1,2)→reached!
```

### Space Complexity: O(N²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Same DFS approach | O(4^(N²)) | Varies | Baseline |
| DFS Backtracking | O(4^(N²)) | O(N²) | Optimal |

**Recommended Solution:** DFS Backtracking

**Key Insights:**
1. **Mark/unmark visited:** Prevents cycles
2. **Lexicographic order:** D,L,R,U ensures sorted output
3. **All paths:** Don't stop at first — continue backtracking

<br><br>

---

```code```
