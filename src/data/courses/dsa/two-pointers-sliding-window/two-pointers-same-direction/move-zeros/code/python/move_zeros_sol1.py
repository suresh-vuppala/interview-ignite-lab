class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        j = 0
        for num in nums:
            if num != 0: nums[j] = num; j += 1
        while j < len(nums): nums[j] = 0; j += 1