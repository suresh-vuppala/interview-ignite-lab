class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # O(n) time, O(n) space — Hash map for complement lookup
        seen = {}  # value -> index
        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
        return []  # No solution found