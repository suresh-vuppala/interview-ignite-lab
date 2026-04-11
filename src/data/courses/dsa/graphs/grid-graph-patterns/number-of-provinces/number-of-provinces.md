Given an n×n adjacency matrix where isConnected[i][j]=1 means city i and j are connected, find the number of provinces (connected components).

<br>

> Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
> Output: 2
> **Key insight:** Same as count connected components but input is adjacency MATRIX instead of edge list. DFS from each unvisited city.

<br>

---

## Constraints
- `1 ≤ n ≤ 200`

<br>

---

## Solution: DFS from Each Unvisited (Optimal)

**Algorithm:** For each city 0..n-1: if not visited → count++, DFS to visit all connected cities.

### Time Complexity: O(N²)
**Why?** Must check N² entries in the adjacency matrix.

### Space Complexity: O(N)

> **Drawback:** None — O(N²) is optimal for adjacency matrix input.

> **Key Insight for Improvement:** Union-Find also works in O(N²×α(N)).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS | O(N²) | O(N) |

**Key Insights:**
1. **Adjacency matrix input:** Check all matrix[i][j]==1 for neighbors
2. **Same as connected components:** Just different input format

<br><br>

---

```code```
