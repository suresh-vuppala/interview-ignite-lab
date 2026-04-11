class Solution:
    def minSubArrayLen(self, target, nums):
        min_len = float('inf')
        for i in range(len(nums)):
            s = 0
            for j in range(i, len(nums)):
                s += nums[j]
                if s >= target: min_len = min(min_len, j-i+1); break
        return 0 if min_len == float('inf') else min_len