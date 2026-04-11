# ============================================================
# Binary Tree Core Operations (BST)
# ============================================================

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

class BSTOperations:
    def insert(self, root, val):
        if not root: return TreeNode(val)
        if val < root.val: root.left = self.insert(root.left, val)
        elif val > root.val: root.right = self.insert(root.right, val)
        return root

    def search(self, root, val):
        if not root: return False
        if val == root.val: return True
        if val < root.val: return self.search(root.left, val)
        return self.search(root.right, val)

    def delete(self, root, val):
        if not root: return None
        if val < root.val: root.left = self.delete(root.left, val)
        elif val > root.val: root.right = self.delete(root.right, val)
        else:
            if not root.left: return root.right
            if not root.right: return root.left
            # Two children: inorder successor
            succ = root.right
            while succ.left: succ = succ.left
            root.val = succ.val
            root.right = self.delete(root.right, succ.val)
        return root
