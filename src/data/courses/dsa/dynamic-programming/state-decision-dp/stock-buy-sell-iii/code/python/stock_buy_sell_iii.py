class Solution:
    def maxProfit(self,prices)->int:
        b1=b2=float('inf');p1=p2=0
        for x in prices:b1=min(b1,x);p1=max(p1,x-b1);b2=min(b2,x-p1);p2=max(p2,x-b2)
        return p2