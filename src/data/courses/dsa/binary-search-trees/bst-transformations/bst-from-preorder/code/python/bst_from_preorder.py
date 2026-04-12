class Solution:
    def bstFromPreorder(self, preorder):
        self.idx = 0
        def build(bound):
            if self.idx >= len(preorder) or preorder[self.idx] > bound: return None
            root = TreeNode(preorder[self.idx]); self.idx += 1
            root.left = build(root.val)
            root.right = build(bound)
            return root
        return build(float('inf'))
