# ============================================================
# Balanced Binary Tree
# ============================================================

class Solution1:
    def isBalanced(self, root) -> bool:
        if not root: return True
        lh = self.height(root.left)
        rh = self.height(root.right)
        return abs(lh-rh)<=1 and self.isBalanced(root.left) and self.isBalanced(root.right)
    def height(self, node):
        if not node: return 0
        return 1 + max(self.height(node.left), self.height(node.right))

class Solution2:
    def isBalanced(self, root) -> bool:
        return self.check(root) != -1
    def check(self, node):
        if not node: return 0
        l = self.check(node.left)
        if l == -1: return -1
        r = self.check(node.right)
        if r == -1: return -1
        if abs(l - r) > 1: return -1
        return 1 + max(l, r)
