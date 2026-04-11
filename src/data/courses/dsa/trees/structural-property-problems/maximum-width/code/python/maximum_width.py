# ============================================================
# Maximum Width of Binary Tree
# ============================================================
from collections import deque
class Solution:
    def widthOfBinaryTree(self, root) -> int:
        if not root: return 0
        max_width = 0
        queue = deque([(root, 0)])  # (node, position)
        while queue:
            size = len(queue)
            min_pos = queue[0][1]  # Normalize to prevent overflow
            first = last = 0
            for i in range(size):
                node, pos = queue.popleft()
                pos -= min_pos
                if i == 0: first = pos
                if i == size - 1: last = pos
                if node.left: queue.append((node.left, 2 * pos))
                if node.right: queue.append((node.right, 2 * pos + 1))
            max_width = max(max_width, last - first + 1)
        return max_width
