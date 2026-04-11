# ============================================================
# Symmetric Tree
# ============================================================

class Solution:
    def isSymmetric(self, root) -> bool:
        def is_mirror(l, r):
            if not l and not r: return True
            if not l or not r: return False
            return (l.val == r.val and
                    is_mirror(l.left, r.right) and
                    is_mirror(l.right, r.left))

        return not root or is_mirror(root.left, root.right)
