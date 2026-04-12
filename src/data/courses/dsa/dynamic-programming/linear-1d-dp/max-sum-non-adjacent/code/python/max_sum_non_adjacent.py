class Solution:
    def maxSumNonAdjacent(self, nums) -> int:
        if not nums: return 0
        a = max(0, nums[0])
        b = max(a, nums[1]) if len(nums) > 1 else a
        for i in range(2, len(nums)): a, b = b, max(b, a + nums[i])
        return b
