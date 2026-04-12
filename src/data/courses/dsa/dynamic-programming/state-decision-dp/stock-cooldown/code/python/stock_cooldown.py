class Solution:
    def maxProfit(self,prices)->int:
        sold,held,rest=0,float('-inf'),0
        for x in prices:ps=sold;sold=held+x;held=max(held,rest-x);rest=max(rest,ps)
        return max(sold,rest)