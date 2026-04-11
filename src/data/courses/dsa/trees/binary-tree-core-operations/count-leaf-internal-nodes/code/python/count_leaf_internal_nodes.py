# ============================================================
# Count Leaf and Internal Nodes
# ============================================================

class Solution:
    def countLeaves(self, root) -> int:
        if not root: return 0
        if not root.left and not root.right: return 1
        return self.countLeaves(root.left) + self.countLeaves(root.right)

    def countInternal(self, root) -> int:
        if not root: return 0
        if not root.left and not root.right: return 0
        return 1 + self.countInternal(root.left) + self.countInternal(root.right)
