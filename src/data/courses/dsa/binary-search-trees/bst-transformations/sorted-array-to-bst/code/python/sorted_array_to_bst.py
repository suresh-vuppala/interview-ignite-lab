class Solution:
    def sortedArrayToBST(self, nums):
        def build(l, r):
            if l > r: return None
            m = (l + r) // 2
            root = TreeNode(nums[m])
            root.left, root.right = build(l, m-1), build(m+1, r)
            return root
        return build(0, len(nums)-1)
