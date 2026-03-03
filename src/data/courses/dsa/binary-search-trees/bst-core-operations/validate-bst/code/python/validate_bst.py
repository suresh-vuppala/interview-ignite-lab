class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def isValidBST(root, minVal=float('-inf'), maxVal=float('inf')):
    if not root:
        return True
    
    if root.val <= minVal or root.val >= maxVal:
        return False
    
    return (isValidBST(root.left, minVal, root.val) and
            isValidBST(root.right, root.val, maxVal))

if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    
    print(f"Is Valid BST: {isValidBST(root)}")
