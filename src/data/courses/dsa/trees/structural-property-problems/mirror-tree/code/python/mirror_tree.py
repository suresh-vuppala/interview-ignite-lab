# ============================================================
# Mirror Binary Tree
# ============================================================
class Solution:
    def mirror(self, root):
        if not root: return None
        root.left, root.right = root.right, root.left
        self.mirror(root.left)
        self.mirror(root.right)
        return root
