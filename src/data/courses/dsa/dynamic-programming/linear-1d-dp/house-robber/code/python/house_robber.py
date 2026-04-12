class Solution:
    def rob(self, nums) -> int:
        if len(nums) == 1: return nums[0]
        a, b = nums[0], max(nums[0], nums[1])
        for i in range(2, len(nums)): a, b = b, max(b, a + nums[i])
        return b
