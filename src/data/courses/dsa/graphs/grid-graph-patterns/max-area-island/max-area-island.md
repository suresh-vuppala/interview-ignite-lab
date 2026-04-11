Find the maximum area of an island in a 2D grid. Area = number of '1' cells in the island.

<br>

> Input: grid = [[0,0,1,0,0],[0,0,0,0,0],[0,1,1,0,0],[0,1,1,0,0]]
> Output: 4
> **Key insight:** Same as Number of Islands but track size during DFS. Return count of cells visited per island.

<br>

---

## Constraints
- `1 ≤ m, n ≤ 50`

<br>

---

## Solution: DFS + Count Cells (Optimal)

**Algorithm:** DFS returns count of cells visited. Track max across all islands.

### Time Complexity: O(M × N)
### Space Complexity: O(M × N)

> **Drawback:** None — must visit all cells.

> **Key Insight for Improvement:** Same sink technique as Number of Islands. DFS returns area instead of void.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS + Area Count | O(M×N) | O(M×N) |

**Key Insights:**
1. **DFS returns area:** 1 + dfs(up) + dfs(down) + dfs(left) + dfs(right)
2. **Sink technique:** Same as Number of Islands
3. **Variation:** Can also track all island sizes for further analysis

<br><br>

---

```code```
