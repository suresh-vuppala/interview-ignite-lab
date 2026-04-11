class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, max_so_far):
            if not node: return 0
            count = 1 if node.val >= max_so_far else 0
            new_max = max(max_so_far, node.val)
            return count + dfs(node.left, new_max) + dfs(node.right, new_max)
        return dfs(root, root.val)