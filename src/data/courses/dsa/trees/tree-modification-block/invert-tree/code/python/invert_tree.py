# ============================================================
# Invert Binary Tree
# ============================================================

class Solution:
    def invertTree(self, root):
        if not root: return None

        # Swap children
        root.left, root.right = root.right, root.left

        # Recursively invert subtrees
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root
