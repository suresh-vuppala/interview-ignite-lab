class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # Hash Set: O(n) time, O(n) space
        s = set(nums)
        for i in range(1, len(nums) + 2):
            if i not in s: return i