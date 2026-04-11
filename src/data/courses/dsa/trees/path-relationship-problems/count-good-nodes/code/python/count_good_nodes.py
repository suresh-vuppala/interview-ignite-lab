# ============================================================
# Count Good Nodes
# ============================================================
class Solution:
    def goodNodes(self, root) -> int:
        def dfs(node, max_so_far):
            if not node: return 0
            count = 1 if node.val >= max_so_far else 0
            max_so_far = max(max_so_far, node.val)
            return count + dfs(node.left, max_so_far) + dfs(node.right, max_so_far)
        return dfs(root, float('-inf'))
