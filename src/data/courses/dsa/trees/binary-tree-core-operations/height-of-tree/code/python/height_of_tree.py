# ============================================================
# Maximum Depth of Binary Tree
# ============================================================

from collections import deque

class Solution1:
    def maxDepth(self, root) -> int:
        if not root: return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

class Solution2:
    def maxDepth(self, root) -> int:
        if not root: return 0
        queue, depth = deque([root]), 0
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            depth += 1
        return depth
