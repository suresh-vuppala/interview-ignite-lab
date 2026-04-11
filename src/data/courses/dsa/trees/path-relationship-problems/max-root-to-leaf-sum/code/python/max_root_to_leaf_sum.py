# ============================================================
# Maximum Root-to-Leaf Path Sum
# ============================================================
class Solution:
    def maxPathSum(self, root) -> int:
        if not root: return float('-inf')
        if not root.left and not root.right: return root.val
        if not root.left: return root.val + self.maxPathSum(root.right)
        if not root.right: return root.val + self.maxPathSum(root.left)
        return root.val + max(self.maxPathSum(root.left), self.maxPathSum(root.right))
