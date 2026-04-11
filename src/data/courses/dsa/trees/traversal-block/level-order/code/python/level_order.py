# ============================================================
# Binary Tree Level Order Traversal
# ============================================================

from typing import List
from collections import deque

class Solution:
    def levelOrder(self, root) -> List[List[int]]:
        if not root: return []
        result, queue = [], deque([root])

        while queue:
            level = []
            for _ in range(len(queue)):  # Process current level
                node = queue.popleft()
                level.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            result.append(level)

        return result
