class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def count_leaf_nodes(root):
    if not root:
        return 0
    if not root.left and not root.right:
        return 1
    return count_leaf_nodes(root.left) + count_leaf_nodes(root.right)

def count_internal_nodes(root):
    if not root or (not root.left and not root.right):
        return 0
    return 1 + count_internal_nodes(root.left) + count_internal_nodes(root.right)

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(f"Leaf nodes: {count_leaf_nodes(root)}")
