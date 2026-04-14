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

## All Possible Edge Cases
1. **No islands:** all 0s → return 0
2. **Single cell island:** area = 1
3. **Entire grid is one island:** area = M*N
4. **L-shaped / irregular islands**

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
> Use DFS + Count Cells (Optimal) for O(M × N) time.

<br>

---

## Solution 2: DFS + Count Cells (Optimal)

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
