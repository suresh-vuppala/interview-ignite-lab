# ============================================================
# Convert BT to DLL
# ============================================================
class Solution:
    def treeToDoublyList(self, root):
        if not root: return None
        self.prev = self.head = None
        def inorder(node):
            if not node: return
            inorder(node.left)
            if not self.prev: self.head = node
            else: self.prev.right = node; node.left = self.prev
            self.prev = node
            inorder(node.right)
        inorder(root)
        return self.head
