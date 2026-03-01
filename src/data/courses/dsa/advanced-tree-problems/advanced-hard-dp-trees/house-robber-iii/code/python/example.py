class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def rob(root):
    def dfs(node):
        if not node:
            return 0, 0
        
        leftRob, leftSkip = dfs(node.left)
        rightRob, rightSkip = dfs(node.right)
        
        rob_val = node.val + leftSkip + rightSkip
        skip_val = max(leftRob, leftSkip) + max(rightRob, rightSkip)
        
        return rob_val, skip_val
    
    rob_val, skip_val = dfs(root)
    return max(rob_val, skip_val)

if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    
    print(f"Max money: {rob(root)}")
