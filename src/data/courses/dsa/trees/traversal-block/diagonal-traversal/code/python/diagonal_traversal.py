# ============================================================
# Diagonal Traversal
# ============================================================
from collections import deque
class Solution:
    def diagonalTraversal(self, root):
        if not root: return []
        result, q = [], deque([root])
        while q:
            diagonal = []
            for _ in range(len(q)):
                node = q.popleft()
                while node:
                    diagonal.append(node.val)
                    if node.left: q.append(node.left)
                    node = node.right
            result.append(diagonal)
        return result
