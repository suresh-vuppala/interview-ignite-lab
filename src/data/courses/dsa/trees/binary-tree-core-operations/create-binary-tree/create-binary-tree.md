## Creating a Binary Tree

**From Array (Level Order):**
Index i: left child at 2i+1, right child at 2i+2. Use BFS with queue.

**From Traversals:**
- Inorder + Preorder → unique tree
- Inorder + Postorder → unique tree
- Preorder + Postorder → NOT unique (ambiguous for single-child nodes)

### Time: O(n) | Space: O(n)

<br>
<br>

---

```code```
