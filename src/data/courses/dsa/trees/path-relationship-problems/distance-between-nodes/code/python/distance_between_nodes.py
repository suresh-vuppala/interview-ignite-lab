# ============================================================
# Distance Between Two Nodes
# ============================================================
class Solution:
    def findDistance(self, root, p: int, q: int) -> int:
        def find_lca(node, p, q):
            if not node or node.val == p or node.val == q: return node
            left = find_lca(node.left, p, q)
            right = find_lca(node.right, p, q)
            return node if left and right else (left or right)
        def depth(node, target, d):
            if not node: return -1
            if node.val == target: return d
            l = depth(node.left, target, d+1)
            return l if l != -1 else depth(node.right, target, d+1)
        lca = find_lca(root, p, q)
        return depth(lca, p, 0) + depth(lca, q, 0)
