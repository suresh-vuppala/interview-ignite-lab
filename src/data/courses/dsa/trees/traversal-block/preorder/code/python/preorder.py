# ============================================================
# Binary Tree Preorder Traversal
# ============================================================

from typing import List

class Solution1:
    def preorderTraversal(self, root) -> List[int]:
        result = []
        def dfs(node):
            if not node: return
            result.append(node.val)
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return result

class Solution2:
    def preorderTraversal(self, root) -> List[int]:
        if not root: return []
        result, stack = [], [root]
        while stack:
            node = stack.pop()
            result.append(node.val)       # Process root
            if node.right: stack.append(node.right)  # Right first
            if node.left: stack.append(node.left)    # Left next
        return result
