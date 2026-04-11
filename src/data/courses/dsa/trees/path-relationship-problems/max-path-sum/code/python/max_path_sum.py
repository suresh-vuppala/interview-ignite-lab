# ============================================================
# Binary Tree Maximum Path Sum
# ============================================================
class Solution:
    def maxPathSum(self, root) -> int:
        self.global_max = float('-inf')

        def max_gain(node):
            if not node: return 0
            left = max(0, max_gain(node.left))   # Ignore negative branches
            right = max(0, max_gain(node.right))
            # Path through this node (uses both sides)
            self.global_max = max(self.global_max, node.val + left + right)
            # Return to parent: can only extend ONE side
            return node.val + max(left, right)

        max_gain(root)
        return self.global_max
