class Solution:
    def maxProduct(self,nums)->int:
        max_p=cur_max=cur_min=nums[0]
        for i in range(1,len(nums)):
            if nums[i]<0:cur_max,cur_min=cur_min,cur_max
            cur_max=max(nums[i],cur_max*nums[i])
            cur_min=min(nums[i],cur_min*nums[i])
            max_p=max(max_p,cur_max)
        return max_p