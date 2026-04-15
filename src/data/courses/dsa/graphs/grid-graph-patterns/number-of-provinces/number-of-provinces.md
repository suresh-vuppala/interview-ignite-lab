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

## All Possible Edge Cases
1. **All connected:** 1 province
2. **All disconnected:** N provinces
3. **Single city**
4. **Dense connections:** many edges but few provinces

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
> Use DFS from Each Unvisited (Optimal) for O(N²) time.

<br>

---

## Solution 2: DFS from Each Unvisited (Optimal)

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
