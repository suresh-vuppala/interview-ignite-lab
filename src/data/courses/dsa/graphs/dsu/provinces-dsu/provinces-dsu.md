Count connected components (provinces) using Union-Find.

<br>

> Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
> Output: 2
> **Key insight:** Union all connected pairs. Count distinct roots = number of components.

<br>

---

## Constraints
- `1 ≤ n ≤ 200`

<br>

---

## Solution: DSU — Union Connected, Count Roots (Optimal)

**Algorithm:** For each pair (i,j) where isConnected[i][j]==1: union(i,j). Count nodes where find(i)==i (roots).

### Time Complexity: O(N² × α(N)) ≈ O(N²)
### Space Complexity: O(N)

> **Drawback:** None — same asymptotic as DFS for matrix input.

> **Key Insight for Improvement:** Count components = N - successful_unions (each union reduces components by 1).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS | O(N²) | O(N) |
| DSU | O(N²·α) | O(N) |

**Key Insights:**
1. **Components = N - unions:** Start with N components, each union merges two
2. **Count roots:** Alternatively, count nodes where parent[i]==i after all unions

<br><br>

---

```code```
