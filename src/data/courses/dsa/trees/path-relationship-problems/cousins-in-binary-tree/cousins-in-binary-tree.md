Given a binary tree and two values x and y, check if nodes with values x and y are cousins. Cousins have the same depth but different parents.

<br>

> Input: root = [1,2,3,4], x = 4, y = 3
> Output: false (4 is depth 2, 3 is depth 1 — different depths)
> **Key insight:** BFS tracking depth and parent for each target node. Compare: same depth AND different parent = cousins.

<br>

---

## Constraints
- `2 ≤ N ≤ 100`

<br>

---

## All Possible Edge Cases
1. **Same parent → NOT cousins (siblings)**
2. **Different depths → NOT cousins**
3. **Root's children: depth 1, no cousins**

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
> Use BFS with Parent + Depth Tracking (Optimal) for O(N) time.

<br>

---

## Solution 2: BFS with Parent + Depth Tracking (Optimal)

**Algorithm:** BFS. For each node, record its depth and parent. Compare depth and parent of x and y.

### Time Complexity: O(N)
**Why?** BFS visits each node once.

### Space Complexity: O(W)

> **Drawback:** None — BFS naturally gives depth.

> **Key Insight for Improvement:** Can also use DFS tracking depth and parent via recursion parameters. Same O(N).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS + Track | O(N) | O(W) |

**Key Insights:**
1. **Two conditions:** Same depth AND different parents
2. **BFS advantage:** Depth is implicit in the level-by-level processing
3. **DFS alternative:** Pass parent and depth as parameters

<br><br>

---

```code```
