class Solution:
    def maxProfit(self,k,prices)->int:
        n=len(prices)
        if k>=n//2:return sum(max(0,prices[i]-prices[i-1])for i in range(1,n))
        buy=[float('inf')]*(k+1);profit=[0]*(k+1)
        for x in prices:
            for i in range(1,k+1):buy[i]=min(buy[i],x-profit[i-1]);profit[i]=max(profit[i],x-buy[i])
        return profit[k]