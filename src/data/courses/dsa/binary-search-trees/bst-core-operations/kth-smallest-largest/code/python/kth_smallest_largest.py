# ============================================================
# Kth Smallest/Largest
# ============================================================
class Solution:
    def kthSmallest(self, root, k):
        self.k, self.result = k, -1
        def inorder(node):
            if not node or self.k <= 0: return
            inorder(node.left)
            self.k -= 1
            if self.k == 0: self.result = node.val; return
            inorder(node.right)
        inorder(root); return self.result

    def kthLargest(self, root, k):
        self.k, self.result = k, -1
        def rev_inorder(node):
            if not node or self.k <= 0: return
            rev_inorder(node.right)
            self.k -= 1
            if self.k == 0: self.result = node.val; return
            rev_inorder(node.left)
        rev_inorder(root); return self.result
