# Time: O(N) | Space: O(H)

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def diameterOfBinaryTree(self, root):
        self.diameter = 0
        
        def dfs(node):
            if not node:
                return 0
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            self.diameter = max(self.diameter, left + right)
            return max(left, right) + 1
        
        dfs(root)
        return self.diameter
