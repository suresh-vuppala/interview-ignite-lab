Construct a BST from a given postorder traversal.

<br>

> Input: postorder = [1,7,5,12,10,8]
> Output: BST with root=8
> **Key insight:** Mirror of preorder construction. Process from RIGHT to LEFT (root is last element). Use LOWER bound. Build right subtree first, then left.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution: Reverse Iteration with Lower Bound (Optimal)

**Algorithm:** Start from last element (root). build(lower_bound): if idx < 0 or postorder[idx] < bound → null. Create node. Right = build(node.val). Left = build(bound).

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** None.

> **Key Insight for Improvement:** Postorder = Left, Right, Root. Reverse = Root, Right, Left. So process from right: root first, then right subtree, then left — mirror of preorder approach.

<br>

---

**Key Insights:**
1. **Reverse postorder = Root, Right, Left:** Mirror of preorder
2. **Lower bound (not upper):** Because we process right subtree first
3. **Same O(N) technique:** Bound-based splitting

<br><br>

---

```code```
