class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Sort: O(n log n) — Sort then scan
        if not nums: return 0
        nums.sort()
        max_len = cur = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]: continue
            if nums[i] == nums[i-1]+1: cur += 1
            else: cur = 1
            max_len = max(max_len, cur)
        return max_len