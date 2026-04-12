Given an m×n grid of heights, find all cells where water can flow to BOTH the Pacific (top/left edges) and Atlantic (bottom/right edges) oceans.

<br>

> Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
> Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
> **Key insight:** Reverse thinking: instead of flowing FROM each cell, flow BACKWARD from oceans. DFS/BFS from Pacific border cells and Atlantic border cells separately. Intersection = cells reaching both.

<br>

---

## Constraints
- `1 ≤ m, n ≤ 200`

<br>

---

## Solution: Reverse DFS from Both Oceans (Optimal)

**Algorithm:**
1. DFS from all Pacific border cells (top row + left column) — mark reachable cells going UPHILL (reverse flow).
2. DFS from all Atlantic border cells (bottom row + right column) — same.
3. Cells in BOTH sets = answer.

### Time Complexity: O(M × N)
**Why?** Two DFS passes, each visiting at most all cells.

**Detailed breakdown:** 200×200 = 40,000 cells × 2 passes

### Space Complexity: O(M × N)

> **Drawback:** None — reverse approach is optimal.

> **Key Insight for Improvement:** Forward approach (DFS from each cell) would be O(M²N²). Reverse from oceans gives O(MN).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Forward DFS per cell | O(M²N²) | O(MN) | Check each cell individually |
| Reverse DFS from oceans | O(MN) | O(MN) | Two passes from borders |

**Key Insights:**
1. **Reverse flow:** Go uphill from ocean — reaches same cells as downhill from source
2. **Two boolean grids:** pacific[i][j] and atlantic[i][j]
3. **Intersection:** Both true = water reaches both oceans

<br><br>

---

```code```
