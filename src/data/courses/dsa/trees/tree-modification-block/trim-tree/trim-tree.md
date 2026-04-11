Trim a BST so that all node values are within [low, high]. Return the root of the trimmed tree.

<br>

> Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
> Output: [3,2,null,1]
> **Key insight:** If node.val < low → entire left subtree is out, trim right subtree. If node.val > high → entire right subtree is out, trim left. Else trim both children.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution: Recursive Trim (Optimal)

**Algorithm:**
1. If root null → null
2. If root.val < low → return trim(root.right, low, high) — skip this node and left subtree
3. If root.val > high → return trim(root.left, low, high) — skip this node and right subtree
4. Else: root.left = trim(left), root.right = trim(right), return root

### Time Complexity: O(N)
**Why?** Visit each node at most once.

### Space Complexity: O(H)

> **Drawback:** None — exploits BST property for efficient pruning.

> **Key Insight for Improvement:** BST property means: if node < low, ALL left descendants < low too (skip entire left subtree). Same for > high and right subtree.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursive Trim | O(N) | O(H) |

**Key Insights:**
1. **BST property enables pruning:** Skip entire subtrees, not just individual nodes
2. **Three cases:** Too small (go right), too large (go left), in range (trim both)
3. **Returns new subtree root:** Handles deletion by returning child directly

<br><br>

---

```code```
