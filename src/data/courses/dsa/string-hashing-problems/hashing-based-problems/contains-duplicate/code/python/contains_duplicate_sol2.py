class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Sort + Scan: O(n log n) — Duplicates become adjacent
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]: return True
        return False