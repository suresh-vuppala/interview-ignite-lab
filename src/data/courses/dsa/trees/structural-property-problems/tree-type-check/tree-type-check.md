Check if a binary tree is: (a) Full — every node has 0 or 2 children, (b) Complete — all levels filled except possibly the last (filled left to right), (c) Perfect — all internal nodes have 2 children and all leaves at same level.

<br>

> Input: root = [1,2,3,4,5,6,7]
> Output: Full=true, Complete=true, Perfect=true

> Explanation: All internal nodes have 2 children, all leaves at level 3, completely filled.
> 
> **Key insight:** Full: DFS check 0 or 2 children. Complete: BFS — once a non-full node is seen, all subsequent must be leaves. Perfect: leftHeight == rightHeight (both go all the way down).

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

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
> Use Type-Specific Checks (Optimal) for O(N) for each check time.

<br>

---

## Solution 2: Type-Specific Checks (Optimal)

**Full Binary Tree:** DFS — each node has exactly 0 or 2 children.

**Complete Binary Tree:** BFS — set flag when encountering a node with < 2 children. After flag, every node must be a leaf.

**Perfect Binary Tree:** Count left-only depth and right-only depth. If equal → 2^h - 1 nodes (perfect).

### Time Complexity: O(N) for each check

### Space Complexity: O(H) or O(W)

> **Drawback:** Separate functions for each type. But each is O(N).

> **Key Insight for Improvement:** Perfect → Complete → any tree forms a hierarchy. Perfect trees are always complete. Complete trees are always binary.

<br>

---

## Complexity Progression Summary

| Check | Time | Space | Method |
|-------|------|-------|--------|
| Full | O(N) | O(H) | DFS: 0 or 2 children |
| Complete | O(N) | O(W) | BFS: flag after non-full node |
| Perfect | O(H) | O(1) | Compare left-only and right-only depths |

**Key Insights:**
1. **Perfect ⊂ Complete ⊂ Binary:** Hierarchy of tree types
2. **Complete BFS trick:** After encountering non-full node, all remaining must be leaves
3. **Perfect shortcut:** If leftH == rightH → perfect (O(H) instead of O(N))

<br><br>

---

```code```
