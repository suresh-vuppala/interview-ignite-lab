class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def isBalanced(root):
    def getHeight(node):
        if not node:
            return 0
        
        left = getHeight(node.left)
        if left == -1:
            return -1
        
        right = getHeight(node.right)
        if right == -1:
            return -1
        
        if abs(left - right) > 1:
            return -1
        
        return 1 + max(left, right)
    
    return getHeight(root) != -1

if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    
    print(f"Is Balanced: {isBalanced(root)}")
