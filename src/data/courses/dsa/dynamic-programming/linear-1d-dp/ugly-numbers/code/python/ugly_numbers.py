class Solution:
    # ============ TABULATION (BOTTOM-UP) ============
    # Memoization not ideal for this problem
    
    def nthUglyNumber(self, n):
        dp = [0] * n
        dp[0] = 1
        
        i2 = i3 = i5 = 0
        
        for i in range(1, n):
            next2 = dp[i2] * 2
            next3 = dp[i3] * 3
            next5 = dp[i5] * 5
            
            dp[i] = min(next2, next3, next5)
            
            if dp[i] == next2:
                i2 += 1
            if dp[i] == next3:
                i3 += 1
            if dp[i] == next5:
                i5 += 1
        
        return dp[n-1]
