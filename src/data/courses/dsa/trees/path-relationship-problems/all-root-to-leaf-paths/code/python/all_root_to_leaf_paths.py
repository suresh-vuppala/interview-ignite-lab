# ============================================================
# All Root-to-Leaf Paths
# ============================================================
class Solution:
    def binaryTreePaths(self, root):
        result = []
        def dfs(node, path):
            path += str(node.val)
            if not node.left and not node.right:
                result.append(path); return
            if node.left: dfs(node.left, path + "->")
            if node.right: dfs(node.right, path + "->")
        if root: dfs(root, "")
        return result
