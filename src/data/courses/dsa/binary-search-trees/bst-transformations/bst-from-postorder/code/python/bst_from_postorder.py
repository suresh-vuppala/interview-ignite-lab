class Solution:
    def bstFromPostorder(self, postorder):
        self.idx = len(postorder) - 1
        def build(bound):
            if self.idx < 0 or postorder[self.idx] < bound: return None
            root = TreeNode(postorder[self.idx]); self.idx -= 1
            root.right = build(root.val)
            root.left = build(bound)
            return root
        return build(float('-inf'))
