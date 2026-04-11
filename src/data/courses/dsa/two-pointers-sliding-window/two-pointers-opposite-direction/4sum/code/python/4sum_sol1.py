class Solution:
    def fourSum(self, nums, target):
        nums.sort(); result = set()
        for i in range(len(nums)-3):
            for j in range(i+1,len(nums)-2):
                for k in range(j+1,len(nums)-1):
                    for l in range(k+1,len(nums)):
                        if nums[i]+nums[j]+nums[k]+nums[l]==target:
                            result.add((nums[i],nums[j],nums[k],nums[l]))
        return [list(t) for t in result]