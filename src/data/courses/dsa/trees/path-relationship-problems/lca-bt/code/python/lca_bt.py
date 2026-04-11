# ============================================================
# Lowest Common Ancestor
# ============================================================
class Solution:
    def lowestCommonAncestor(self, root, p, q):
        if not root or root == p or root == q: return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right: return root  # Split point = LCA
        return left or right
