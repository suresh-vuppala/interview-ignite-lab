class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def sortedArrayToBST(nums, left=None, right=None):
    if left is None:
        left = 0
    if right is None:
        right = len(nums) - 1
    
    if left > right:
        return None
    
    mid = (left + right) // 2
    root = TreeNode(nums[mid])
    
    root.left = sortedArrayToBST(nums, left, mid - 1)
    root.right = sortedArrayToBST(nums, mid + 1, right)
    
    return root

if __name__ == "__main__":
    nums = [-10, -3, 0, 5, 9]
    root = sortedArrayToBST(nums)
    print(f"BST created with root: {root.val}")
