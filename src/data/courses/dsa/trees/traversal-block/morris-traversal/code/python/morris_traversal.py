# ============================================================
# Morris Inorder Traversal
# ============================================================
class Solution:
    def morrisInorder(self, root):
        result, current = [], root
        while current:
            if not current.left:
                result.append(current.val)
                current = current.right
            else:
                pred = current.left
                while pred.right and pred.right != current:
                    pred = pred.right
                if not pred.right:
                    pred.right = current  # Create thread
                    current = current.left
                else:
                    pred.right = None  # Remove thread
                    result.append(current.val)
                    current = current.right
        return result
