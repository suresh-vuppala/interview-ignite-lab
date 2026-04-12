class Solution:
    def buildTree(self, preorder, inorder):
        in_map = {v: i for i, v in enumerate(inorder)}
        self.pre_idx = 0
        def build(l, r):
            if l > r: return None
            root = TreeNode(preorder[self.pre_idx]); self.pre_idx += 1
            idx = in_map[root.val]
            root.left = build(l, idx - 1)
            root.right = build(idx + 1, r)
            return root
        return build(0, len(inorder) - 1)
