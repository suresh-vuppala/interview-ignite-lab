# ============================================================
# BST Core Operations
# ============================================================
class Solution:
    def search(self, root, val):
        if not root or root.val == val: return root
        return self.search(root.left, val) if val < root.val else self.search(root.right, val)

    def insert(self, root, val):
        if not root: return TreeNode(val)
        if val < root.val: root.left = self.insert(root.left, val)
        elif val > root.val: root.right = self.insert(root.right, val)
        return root

    def deleteNode(self, root, key):
        if not root: return None
        if key < root.val: root.left = self.deleteNode(root.left, key)
        elif key > root.val: root.right = self.deleteNode(root.right, key)
        else:
            if not root.left: return root.right
            if not root.right: return root.left
            succ = root.right
            while succ.left: succ = succ.left
            root.val = succ.val
            root.right = self.deleteNode(root.right, succ.val)
        return root
