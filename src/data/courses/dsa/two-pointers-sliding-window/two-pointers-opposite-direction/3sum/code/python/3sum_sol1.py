class Solution:
    def threeSum(self, nums):
        nums.sort()
        result = set()
        for i in range(len(nums)-2):
            for j in range(i+1, len(nums)-1):
                for k in range(j+1, len(nums)):
                    if nums[i]+nums[j]+nums[k] == 0:
                        result.add((nums[i],nums[j],nums[k]))
        return [list(t) for t in result]