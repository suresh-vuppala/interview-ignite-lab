class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def isSameTree(p, q):
    if not p and not q:
        return True
    if not p or not q:
        return False
    return (p.val == q.val and isSameTree(p.left, q.left) and isSameTree(p.right, q.right))

def isSubtree(root, subRoot):
    if not root:
        return False
    
    if isSameTree(root, subRoot):
        return True
    
    return isSubtree(root.left, subRoot) or isSubtree(root.right, subRoot)

if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(4)
    root.right = TreeNode(5)
    
    subRoot = TreeNode(4)
    subRoot.left = TreeNode(1)
    subRoot.right = TreeNode(2)
    
    print(f"Is subtree: {isSubtree(root, subRoot)}")
