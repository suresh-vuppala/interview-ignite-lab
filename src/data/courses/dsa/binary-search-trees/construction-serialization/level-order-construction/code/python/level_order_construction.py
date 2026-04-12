from collections import deque
class Solution:
    def buildFromLevelOrder(self, vals):
        if not vals or vals[0] is None: return None
        root = TreeNode(vals[0])
        queue, i = deque([root]), 1
        while queue and i < len(vals):
            parent = queue.popleft()
            if i < len(vals) and vals[i] is not None:
                parent.left = TreeNode(vals[i]); queue.append(parent.left)
            i += 1
            if i < len(vals) and vals[i] is not None:
                parent.right = TreeNode(vals[i]); queue.append(parent.right)
            i += 1
        return root
