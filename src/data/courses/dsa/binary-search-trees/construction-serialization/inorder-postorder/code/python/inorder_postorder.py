class Solution:
    def buildTree(self, inorder, postorder):
        in_map = {v: i for i, v in enumerate(inorder)}
        self.post_idx = len(postorder) - 1
        def build(l, r):
            if l > r: return None
            root = TreeNode(postorder[self.post_idx]); self.post_idx -= 1
            idx = in_map[root.val]
            root.right = build(idx + 1, r)  # Right first!
            root.left = build(l, idx - 1)
            return root
        return build(0, len(inorder) - 1)
