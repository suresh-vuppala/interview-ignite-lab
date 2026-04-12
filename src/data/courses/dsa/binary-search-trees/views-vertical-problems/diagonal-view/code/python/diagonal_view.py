from collections import deque
class Solution:
    def diagonalView(self, root):
        if not root: return []
        result, q = [], deque([root])
        while q:
            diag = []
            for _ in range(len(q)):
                node = q.popleft()
                while node:
                    diag.append(node.val)
                    if node.left: q.append(node.left)
                    node = node.right
            result.append(diag)
        return result
