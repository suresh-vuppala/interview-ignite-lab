# ============================================================
# Floor and Ceil in BST
# ============================================================
class Solution:
    def floor(self, root, key):
        result = -1
        while root:
            if root.val == key: return key
            if root.val < key: result = root.val; root = root.right
            else: root = root.left
        return result

    def ceil(self, root, key):
        result = -1
        while root:
            if root.val == key: return key
            if root.val > key: result = root.val; root = root.left
            else: root = root.right
        return result
