class Solution:
    def rob(self, nums) -> int:
        if len(nums) == 1: return nums[0]
        def rob_range(lo, hi):
            a = b = 0
            for i in range(lo, hi + 1): a, b = b, max(b, a + nums[i])
            return b
        return max(rob_range(0, len(nums)-2), rob_range(1, len(nums)-1))
