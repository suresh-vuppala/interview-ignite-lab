from collections import deque
class Solution:
    def topView(self, root):
        if not root: return []
        hd_map = {}
        queue = deque([(root, 0)])
        while queue:
            node, hd = queue.popleft()
            if hd not in hd_map: hd_map[hd] = node.val
            if node.left: queue.append((node.left, hd-1))
            if node.right: queue.append((node.right, hd+1))
        return [hd_map[k] for k in sorted(hd_map)]
