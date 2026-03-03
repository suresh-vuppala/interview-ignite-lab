class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def inorder_recursive(root, result=None):
    if result is None:
        result = []
    if not root:
        return result
    inorder_recursive(root.left, result)
    result.append(root.val)
    inorder_recursive(root.right, result)
    return result

def inorder_iterative(root):
    result = []
    stack = []
    curr = root
    
    while curr or stack:
        while curr:
            stack.append(curr)
            curr = curr.left
        curr = stack.pop()
        result.append(curr.val)
        curr = curr.right
    
    return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(inorder_recursive(root))
