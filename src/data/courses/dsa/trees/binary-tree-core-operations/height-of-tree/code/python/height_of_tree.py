class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def get_height(root):
    if not root:
        return 0
    return 1 + max(get_height(root.left), get_height(root.right))

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(f"Height: {get_height(root)}")
