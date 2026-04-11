# ============================================================
# Flatten Binary Tree to Linked List
# ============================================================
class Solution:
    def flatten(self, root) -> None:
        self.prev = None
        def helper(node):
            if not node: return
            helper(node.right)
            helper(node.left)
            node.right = self.prev
            node.left = None
            self.prev = node
        helper(root)
