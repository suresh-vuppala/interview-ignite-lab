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
> Use Recursive Trim (Optimal) for O(N) time.

<br>

---

## Solution 2: Recursive Trim (Optimal)

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
