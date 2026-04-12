from collections import deque
class Solution:
    def deserialize(self, data):
        if data == 'null': return None
        vals = data.split(',')
        root = TreeNode(int(vals[0]))
        queue, i = deque([root]), 1
        while queue and i < len(vals):
            parent = queue.popleft()
            if vals[i] != 'null':
                parent.left = TreeNode(int(vals[i])); queue.append(parent.left)
            i += 1
            if i < len(vals) and vals[i] != 'null':
                parent.right = TreeNode(int(vals[i])); queue.append(parent.right)
            i += 1
        return root
