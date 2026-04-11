Find cells where water can flow to both Pacific (top/left) and Atlantic (bottom/right) oceans.

<br>

---

## Solution 1: DFS/BFS from Every Cell — O(m²n²) — Check each cell's reachability

<br>

---

## Solution 2: Reverse DFS from Oceans (Optimal)

**Intuition:** Instead of checking each cell → ocean, reverse: start from ocean borders and DFS/BFS uphill. Find intersection of Pacific-reachable and Atlantic-reachable cells.

**Algorithm:**
1. DFS from all Pacific border cells (top row + left col) — mark pac[i][j]
2. DFS from all Atlantic border cells (bottom row + right col) — mark atl[i][j]
3. Result = cells where both pac and atl are true

### Time: O(m × n) | Space: O(m × n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Per-cell check | O(m²n²) | O(m×n) | DFS from every cell |
| Reverse from oceans | O(m×n) | O(m×n) | Two DFS from borders, intersect |

<br>
<br>

---

```code```
