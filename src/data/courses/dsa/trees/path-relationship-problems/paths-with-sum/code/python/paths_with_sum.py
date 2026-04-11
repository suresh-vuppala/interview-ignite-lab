# ============================================================
# Path Sum II
# ============================================================
class Solution:
    def pathSum(self, root, targetSum):
        result = []
        def dfs(node, remain, path):
            if not node: return
            path.append(node.val)
            remain -= node.val
            if not node.left and not node.right and remain == 0:
                result.append(list(path))  # Copy path
            dfs(node.left, remain, path)
            dfs(node.right, remain, path)
            path.pop()  # Backtrack
        dfs(root, targetSum, [])
        return result
