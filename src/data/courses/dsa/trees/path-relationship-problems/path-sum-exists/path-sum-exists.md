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

## Solution: DFS — Subtract and Check at Leaf (Optimal)

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
