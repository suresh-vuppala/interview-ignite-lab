# ============================================================
# Max and Min Value in Binary Tree
# ============================================================

class Solution1:
    def findMax(self, root) -> int:
        if not root: return float('-inf')
        return max(root.val, self.findMax(root.left), self.findMax(root.right))

    def findMin(self, root) -> int:
        if not root: return float('inf')
        return min(root.val, self.findMin(root.left), self.findMin(root.right))

class Solution2:
    def findBSTMin(self, root) -> int:
        while root.left: root = root.left
        return root.val

    def findBSTMax(self, root) -> int:
        while root.right: root = root.right
        return root.val
