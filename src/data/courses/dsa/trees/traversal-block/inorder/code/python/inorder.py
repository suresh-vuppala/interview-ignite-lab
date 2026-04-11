# ============================================================
# Binary Tree Inorder Traversal
# ============================================================

from typing import List, Optional

class Solution1:
    def inorderTraversal(self, root) -> List[int]:
        result = []
        def dfs(node):
            if not node: return
            dfs(node.left)           # Left
            result.append(node.val)  # Root
            dfs(node.right)          # Right
        dfs(root)
        return result

class Solution2:
    def inorderTraversal(self, root) -> List[int]:
        result, stack, current = [], [], root
        while current or stack:
            while current:
                stack.append(current)
                current = current.left
            current = stack.pop()
            result.append(current.val)
            current = current.right
        return result

class Solution3:
    def inorderTraversal(self, root) -> List[int]:
        result, current = [], root
        while current:
            if not current.left:
                result.append(current.val)
                current = current.right
            else:
                pred = current.left
                while pred.right and pred.right != current:
                    pred = pred.right
                if not pred.right:
                    pred.right = current
                    current = current.left
                else:
                    pred.right = None
                    result.append(current.val)
                    current = current.right
        return result
