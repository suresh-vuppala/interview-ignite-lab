class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Brute Force: O(n²) time, O(1) space — Check every pair
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []