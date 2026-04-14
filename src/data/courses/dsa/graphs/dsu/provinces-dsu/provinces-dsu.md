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
> Use DSU — Union Connected, Count Roots (Optimal) for O(N² × α(N)) ≈ O(N²) time.

<br>

---

## Solution 2: DSU — Union Connected, Count Roots (Optimal)

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
