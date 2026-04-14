Given a binary tree and a target sum, determine if the tree has a root-to-leaf path where values sum to target.

<br>

> Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], target = 22
> Output: true (path: 5→4→11→2 = 22)
> **Key insight:** DFS subtracting current value from target. At leaf, check if remaining target == 0.

<br>

---

## Constraints
- `-1000 ≤ Node.val ≤ 1000`, `-1000 ≤ targetSum ≤ 1000`

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
> Use DFS — Subtract and Check at Leaf (Optimal) for O(N) time.

<br>

---

## Solution 2: DFS — Subtract and Check at Leaf (Optimal)

**Algorithm:** hasPathSum(node, remaining). Subtract node.val. At leaf: return remaining == 0. Else: recurse left OR right.

### Time Complexity: O(N)
**Why?** Visit each node at most once.

**Detailed breakdown:** N = 5000 → at most 5000 operations

### Space Complexity: O(H)

> **Drawback:** None — O(N) is optimal. Must check all paths in worst case.

> **Key Insight for Improvement:** Early termination when target found. But worst case still O(N).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS subtract | O(N) | O(H) |

**Key Insights:**
1. **Subtract, don't accumulate:** Pass remaining = target - node.val down
2. **Leaf check:** MUST be both children null — not just any null child
3. **Foundation for Path Sum II:** Same pattern but collect all valid paths

<br><br>

---

```code```
