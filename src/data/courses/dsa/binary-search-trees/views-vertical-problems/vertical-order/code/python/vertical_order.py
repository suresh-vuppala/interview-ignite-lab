from collections import deque, defaultdict
class Solution:
    def verticalOrder(self, root):
        if not root: return []
        cols = defaultdict(list)
        queue = deque([(root, 0)])
        while queue:
            node, hd = queue.popleft()
            cols[hd].append(node.val)
            if node.left: queue.append((node.left, hd-1))
            if node.right: queue.append((node.right, hd+1))
        return [cols[k] for k in sorted(cols)]
