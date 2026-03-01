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
    
    return (p.val == q.val and 
            isSameTree(p.left, q.left) and 
            isSameTree(p.right, q.right))

if __name__ == "__main__":
    p = TreeNode(1)
    p.left = TreeNode(2)
    p.right = TreeNode(3)
    
    q = TreeNode(1)
    q.left = TreeNode(2)
    q.right = TreeNode(3)
    
    print(f"Same tree: {isSameTree(p, q)}")
