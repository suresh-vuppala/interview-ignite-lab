class Solution:
    def sortColors(self, nums):
        cnt = [nums.count(0), nums.count(1), nums.count(2)]
        idx = 0
        for c in range(3):
            for _ in range(cnt[c]): nums[idx] = c; idx += 1