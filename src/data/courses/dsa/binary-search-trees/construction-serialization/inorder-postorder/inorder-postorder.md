Construct a binary tree from inorder and postorder traversal arrays.

<br>

> Input: inorder=[9,3,15,20,7], postorder=[9,15,7,20,3]
> Output: tree [3,9,20,null,null,15,7]
> **Key insight:** Postorder's LAST element = root. Find root in inorder → split. Process from right to left in postorder. Build RIGHT subtree first, then left (reverse of preorder approach).

<br>

---

## Constraints
- `1 ≤ N ≤ 3000`

<br>

---

## Solution: Recursive Split — Reverse of Preorder Approach (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** None.

> **Key Insight for Improvement:** Postorder = Left, Right, Root. So last element = root, and we process right-to-left building right subtree before left.

<br>

---

**Key Insights:**
1. **Postorder last = root:** Mirror of preorder first = root
2. **Build right first:** When processing postorder right-to-left, right subtree comes before left
3. **Same hash map trick:** O(1) root lookup in inorder

<br><br>

---

```code```
