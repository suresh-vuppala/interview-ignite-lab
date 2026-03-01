class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def preorder_recursive(root, result=None):
    if result is None:
        result = []
    if not root:
        return result
    result.append(root.val)
    preorder_recursive(root.left, result)
    preorder_recursive(root.right, result)
    return result

def preorder_iterative(root):
    if not root:
        return []
    result = []
    stack = [root]
    
    while stack:
        curr = stack.pop()
        result.append(curr.val)
        if curr.right:
            stack.append(curr.right)
        if curr.left:
            stack.append(curr.left)
    
    return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(preorder_recursive(root))
