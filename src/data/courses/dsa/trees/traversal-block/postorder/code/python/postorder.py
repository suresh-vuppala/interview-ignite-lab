# ============================================================
# Binary Tree Postorder Traversal
# ============================================================

from typing import List

class Solution1:
    def postorderTraversal(self, root) -> List[int]:
        result = []
        def dfs(node):
            if not node: return
            dfs(node.left); dfs(node.right); result.append(node.val)
        dfs(root); return result

class Solution2:
    def postorderTraversal(self, root) -> List[int]:
        if not root: return []
        result, stack = [], [root]
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.left: stack.append(node.left)   # Left first
            if node.right: stack.append(node.right)  # Right next
        return result[::-1]  # Reverse: Root→R→L becomes L→R→Root
