# ============================================================
# Add One Row to Tree
# ============================================================
class Solution:
    def addOneRow(self, root, val: int, depth: int):
        if depth == 1:
            new_root = TreeNode(val)
            new_root.left = root
            return new_root
        def dfs(node, cur):
            if not node: return
            if cur == depth - 1:
                nl, nr = TreeNode(val), TreeNode(val)
                nl.left, nr.right = node.left, node.right
                node.left, node.right = nl, nr
                return
            dfs(node.left, cur+1); dfs(node.right, cur+1)
        dfs(root, 1)
        return root
