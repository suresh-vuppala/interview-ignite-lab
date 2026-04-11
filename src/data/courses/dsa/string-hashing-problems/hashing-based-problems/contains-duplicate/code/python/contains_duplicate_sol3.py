class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Optimal: O(n) — Set comparison
        return len(nums) != len(set(nums))