class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # Optimal: O(n) time, O(1) space — Cyclic sort
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i]-1] != nums[i]:
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        for i in range(n):
            if nums[i] != i + 1: return i + 1
        return n + 1