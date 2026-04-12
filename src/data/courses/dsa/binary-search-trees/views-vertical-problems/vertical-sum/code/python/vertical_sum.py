from collections import deque, defaultdict
class Solution:
    def verticalSum(self, root):
        if not root: return []
        sums = defaultdict(int)
        queue = deque([(root, 0)])
        while queue:
            node, hd = queue.popleft()
            sums[hd] += node.val
            if node.left: queue.append((node.left, hd-1))
            if node.right: queue.append((node.right, hd+1))
        return [sums[k] for k in sorted(sums)]
