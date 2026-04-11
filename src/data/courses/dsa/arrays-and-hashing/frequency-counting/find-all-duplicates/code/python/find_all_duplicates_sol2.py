class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        # Optimal: O(1) space — Negate at index to mark visited
        result = []
        for num in nums:
            idx = abs(num) - 1
            if nums[idx] < 0: result.append(idx + 1)
            else: nums[idx] = -nums[idx]
        return result