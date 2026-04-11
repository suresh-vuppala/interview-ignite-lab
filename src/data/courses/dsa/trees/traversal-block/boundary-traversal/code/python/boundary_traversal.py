# ============================================================
# Boundary Traversal
# ============================================================
class Solution:
    def boundaryTraversal(self, root):
        if not root: return []
        is_leaf = lambda n: n and not n.left and not n.right
        result = []
        if not is_leaf(root): result.append(root.val)
        # Left boundary
        n = root.left
        while n:
            if not is_leaf(n): result.append(n.val)
            n = n.left if n.left else n.right
        # Leaves
        def add_leaves(node):
            if not node: return
            if is_leaf(node): result.append(node.val); return
            add_leaves(node.left); add_leaves(node.right)
        add_leaves(root)
        # Right boundary (reversed)
        temp, n = [], root.right
        while n:
            if not is_leaf(n): temp.append(n.val)
            n = n.right if n.right else n.left
        result.extend(reversed(temp))
        return result
