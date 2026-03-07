# Time: O(N) | Space: O(H)

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def minCameraCover(self, root):
        self.cameras = 0
        
        def dfs(node):
            if not node:
                return 2  # Monitored
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            if left == 0 or right == 0:
                self.cameras += 1
                return 1  # Has camera
            
            if left == 1 or right == 1:
                return 2  # Monitored
            
            return 0  # Not monitored
        
        return self.cameras + (1 if dfs(root) == 0 else 0)
