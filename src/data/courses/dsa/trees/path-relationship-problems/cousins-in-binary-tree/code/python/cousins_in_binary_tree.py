# ============================================================
# Cousins in Binary Tree
# ============================================================
from collections import deque
class Solution:
    def isCousins(self, root, x: int, y: int) -> bool:
        queue = deque([(root, None)])  # (node, parent)
        while queue:
            x_parent = y_parent = None
            for _ in range(len(queue)):
                node, parent = queue.popleft()
                if node.val == x: x_parent = parent
                if node.val == y: y_parent = parent
                if node.left: queue.append((node.left, node))
                if node.right: queue.append((node.right, node))
            if x_parent and y_parent: return x_parent != y_parent
            if x_parent or y_parent: return False
        return False
