# ============================================================
# Diameter of Binary Tree
# ============================================================

class Solution:
    def diameterOfBinaryTree(self, root) -> int:
        self.diameter = 0

        def height(node):
            if not node: return 0
            left_h = height(node.left)
            right_h = height(node.right)
            # Diameter through this node = left + right
            self.diameter = max(self.diameter, left_h + right_h)
            return 1 + max(left_h, right_h)

        height(root)
        return self.diameter
