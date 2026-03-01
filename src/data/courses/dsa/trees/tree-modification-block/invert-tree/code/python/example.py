class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def invertTree(root):
    if not root:
        return None
    
    root.left, root.right = root.right, root.left
    
    invertTree(root.left)
    invertTree(root.right)
    
    return root

if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    
    invertTree(root)
    print("Tree inverted.")
