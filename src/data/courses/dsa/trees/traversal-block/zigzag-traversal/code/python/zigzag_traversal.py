# ============================================================
# Zigzag Level Order Traversal
# ============================================================

from typing import List
from collections import deque

class Solution:
    def zigzagLevelOrder(self, root) -> List[List[int]]:
        if not root: return []
        result, queue = [], deque([root])
        left_to_right = True

        while queue:
            level = []
            for _ in range(len(queue)):
                node = queue.popleft()
                level.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)

            result.append(level if left_to_right else level[::-1])
            left_to_right = not left_to_right

        return result
