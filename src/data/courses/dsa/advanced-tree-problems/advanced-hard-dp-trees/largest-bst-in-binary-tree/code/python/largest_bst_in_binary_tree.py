# Time: O(N) | Space: O(H)

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def largestBSTSubtree(self, root):
        def dfs(node):
            if not node:
                return True, 0, float('inf'), float('-inf')
            
            left_is_bst, left_size, left_min, left_max = dfs(node.left)
            right_is_bst, right_size, right_min, right_max = dfs(node.right)
            
            if left_is_bst and right_is_bst and left_max < node.val < right_min:
                size = left_size + right_size + 1
                return True, size, min(left_min, node.val), max(right_max, node.val)
            
            return False, max(left_size, right_size), 0, 0
        
        return dfs(root)[1]
