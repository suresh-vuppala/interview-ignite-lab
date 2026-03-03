class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def find_min_max(root):
    if not root:
        return (float('inf'), float('-inf'))
    
    left_min, left_max = find_min_max(root.left)
    right_min, right_max = find_min_max(root.right)
    
    min_val = min(root.val, left_min, right_min)
    max_val = max(root.val, left_max, right_max)
    
    return (min_val, max_val)

if __name__ == "__main__":
    root = TreeNode(10)
    root.left = TreeNode(5)
    root.right = TreeNode(15)
    min_val, max_val = find_min_max(root)
    print(f"Min: {min_val}, Max: {max_val}")
