class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def postorder_recursive(root, result=None):
    if result is None:
        result = []
    if not root:
        return result
    postorder_recursive(root.left, result)
    postorder_recursive(root.right, result)
    result.append(root.val)
    return result

def postorder_iterative(root):
    if not root:
        return []
    result = []
    stack = []
    curr = root
    last_visited = None
    
    while curr or stack:
        while curr:
            stack.append(curr)
            curr = curr.left
        top = stack[-1]
        if top.right and top.right != last_visited:
            curr = top.right
        else:
            result.append(top.val)
            last_visited = stack.pop()
    
    return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(postorder_recursive(root))
