from collections import deque
class Solution:
    def leftView(self, root):
        if not root: return []
        result, queue = [], deque([root])
        while queue:
            result.append(queue[0].val)  # First at this level
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
        return result
