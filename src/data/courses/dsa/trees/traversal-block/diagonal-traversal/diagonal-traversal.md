Print the diagonal traversal of a binary tree. Nodes on the same diagonal (root to top-right) are grouped together.

<br>

> Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
> Output: [[8,10,14],[3,6,7,13],[1,4]]

> Explanation: Diagonal 0: 8→10→14. Diagonal 1: 3→6→7→13. Diagonal 2: 1→4.
> 
> **Key insight:** Going right stays on the same diagonal. Going left moves to the next diagonal. Use BFS with a queue: process current node, enqueue left child (next diagonal), move right (same diagonal).

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Right-skewed:** all in one diagonal
2. **Left-skewed:** each separate diagonal
3. **Single node**

<br>

---

## Solution 1: DFS with diagonal index

**Intuition:**
The most straightforward approach — dfs collecting by diagonal needs sorting.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N log N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> DFS collecting by diagonal needs sorting. BFS diagonal grouping avoids sorting.

> **Key Insight for Improvement:**
> Use BFS Diagonal Groups (Optimal) for O(N) time.

<br>

---

## Solution 2: BFS Diagonal Groups (Optimal)

**Algorithm:**
1. Queue starts with root
2. For each diagonal: process all nodes in queue. For each node: follow right chain (same diagonal), enqueue any left children (next diagonal).

### Time Complexity: O(N)
**Why?** Each node visited exactly once.

**Detailed breakdown:** N = 100,000 → 100,000 operations

### Space Complexity: O(W)

> **Drawback:** None — BFS is natural fit for diagonal grouping.

> **Key Insight for Improvement:** Alternative: DFS with diagonal index parameter (node, d). Right child stays at d, left child goes to d+1. Group by d using a map.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS | O(N) | O(W) |
| DFS + Map | O(N) | O(N) |

**Key Insights:**
1. **Right = same diagonal, Left = next diagonal**
2. **Queue naturally groups by diagonal level**

<br><br>

---

```code```
