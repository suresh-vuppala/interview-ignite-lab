class Solution:
    def longestBitonic(self, nums):
        n=len(nums); inc=[1]*n; dec=[1]*n
        for i in range(1,n):
            for j in range(i):
                if nums[j]<nums[i]: inc[i]=max(inc[i],inc[j]+1)
        for i in range(n-2,-1,-1):
            for j in range(n-1,i,-1):
                if nums[j]<nums[i]: dec[i]=max(dec[i],dec[j]+1)
        return max(inc[i]+dec[i]-1 for i in range(n))
