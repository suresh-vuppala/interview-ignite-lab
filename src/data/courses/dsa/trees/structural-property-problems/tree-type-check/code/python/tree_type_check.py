# ============================================================
# Tree Type Checks
# ============================================================
from collections import deque
class Solution:
    def isFullTree(self, root) -> bool:
        if not root: return True
        if bool(root.left) != bool(root.right): return False
        return self.isFullTree(root.left) and self.isFullTree(root.right)

    def isComplete(self, root) -> bool:
        if not root: return True
        queue = deque([root])
        seen_non_full = False
        while queue:
            node = queue.popleft()
            if node.left:
                if seen_non_full: return False
                queue.append(node.left)
            else: seen_non_full = True
            if node.right:
                if seen_non_full: return False
                queue.append(node.right)
            else: seen_non_full = True
        return True

    def isPerfect(self, root) -> bool:
        lh, rh, l, r = 0, 0, root, root
        while l: lh += 1; l = l.left
        while r: rh += 1; r = r.right
        return lh == rh
