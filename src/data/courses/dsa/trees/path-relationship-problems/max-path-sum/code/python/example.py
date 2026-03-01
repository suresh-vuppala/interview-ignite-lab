class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def maxPathSum(root):
    maxSum = [float('-inf')]
    
    def dfs(node):
        if not node:
            return 0
        
        leftSum = max(0, dfs(node.left))
        rightSum = max(0, dfs(node.right))
        
        pathSum = node.val + leftSum + rightSum
        maxSum[0] = max(maxSum[0], pathSum)
        
        return node.val + max(leftSum, rightSum)
    
    dfs(root)
    return maxSum[0]

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    
    print(f"Max Path Sum: {maxPathSum(root)}")
