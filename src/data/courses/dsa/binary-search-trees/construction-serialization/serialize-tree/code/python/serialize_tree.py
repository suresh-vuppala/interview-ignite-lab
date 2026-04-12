from collections import deque
class Solution:
    def serialize(self, root):
        if not root: return 'null'
        result, queue = [], deque([root])
        while queue:
            node = queue.popleft()
            if node:
                result.append(str(node.val))
                queue.append(node.left); queue.append(node.right)
            else:
                result.append('null')
        return ','.join(result)
