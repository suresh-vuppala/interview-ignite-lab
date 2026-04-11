class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # O(n) time, O(n) space — Set comparison
        return len(nums) != len(set(nums))