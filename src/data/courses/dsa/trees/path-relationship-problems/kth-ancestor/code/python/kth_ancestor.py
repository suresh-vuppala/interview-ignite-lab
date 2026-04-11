# ============================================================
# Kth Ancestor
# ============================================================
class Solution:
    def findKthAncestor(self, root, target: int, k: int) -> int:
        path = []
        def find_path(node):
            if not node: return False
            path.append(node)
            if node.val == target: return True
            if find_path(node.left) or find_path(node.right): return True
            path.pop()
            return False
        find_path(root)
        idx = len(path) - 1 - k
        return path[idx].val if idx >= 0 else -1
