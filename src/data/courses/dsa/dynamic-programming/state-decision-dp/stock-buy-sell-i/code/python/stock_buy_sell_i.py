class Solution:
    def maxProfit(self,prices)->int:
        min_p,max_p=float('inf'),0
        for p in prices:min_p=min(min_p,p);max_p=max(max_p,p-min_p)
        return max_p