Find all eventual safe nodes in a directed graph. A node is safe if every path starting from it leads to a terminal node (node with no outgoing edges).

<br>

> Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
> Output: [2,4,5,6]
> **Key insight:** Nodes in cycles are NOT safe. Use reverse DFS 3-coloring: safe=2(black), in-cycle=1(gray). Or reverse graph + Kahn's from terminal nodes.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **Terminal nodes (no outgoing):** always safe
2. **All nodes in cycle:** no safe nodes
3. **Node leading to both cycle and terminal**

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
> Use DFS 3-Coloring (Optimal) for O(V + E) time.

<br>

---

## Solution 2: DFS 3-Coloring (Optimal)

**Algorithm:** Color: 0=white, 1=gray(unsafe/cycle), 2=black(safe). DFS: if all successors are safe → this node is safe. If any successor is gray → this node is unsafe.

### Time Complexity: O(V + E)
### Space Complexity: O(V)

> **Drawback:** None.

> **Key Insight for Improvement:** Alternative: reverse the graph. Terminal nodes have in-degree 0 in the reversed graph. Kahn's from them finds all safe nodes.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS 3-Color | O(V+E) | O(V) |
| Reverse + Kahn's | O(V+E) | O(V+E) |

**Key Insights:**
1. **Safe = not in any cycle AND not reachable from cycle**
2. **Terminal node = safe (base case):** No outgoing edges
3. **3-color determines:** Black = safe, Gray = in cycle or leads to cycle

<br><br>

---

```code```
