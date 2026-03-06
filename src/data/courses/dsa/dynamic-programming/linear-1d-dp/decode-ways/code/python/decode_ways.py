class Solution:
    # ============ MEMOIZATION (TOP-DOWN) ============
    def numDecodingsMemo(self, s):
        n = len(s)
        memo = {}
        
        def dp(i):
            if i == n:
                return 1
            if s[i] == '0':
                return 0
            if i in memo:
                return memo[i]
            
            ways = dp(i + 1)
            if i + 1 < n and (s[i] == '1' or (s[i] == '2' and s[i+1] <= '6')):
                ways += dp(i + 2)
            
            memo[i] = ways
            return ways
        
        return dp(0)
    
    # ============ TABULATION (BOTTOM-UP) ============
    def numDecodingsTab(self, s):
        n = len(s)
        if s[0] == '0':
            return 0
        
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        
        for i in range(2, n + 1):
            if s[i-1] != '0':
                dp[i] += dp[i-1]
            
            two_digit = int(s[i-2:i])
            if 10 <= two_digit <= 26:
                dp[i] += dp[i-2]
        
        return dp[n]
    
    # ============ SPACE OPTIMIZED ============
    def numDecodings(self, s):
        if s[0] == '0':
            return 0
        
        prev2, prev1 = 1, 1
        
        for i in range(2, len(s) + 1):
            curr = 0
            if s[i-1] != '0':
                curr += prev1
            
            two_digit = int(s[i-2:i])
            if 10 <= two_digit <= 26:
                curr += prev2
            
            prev2, prev1 = prev1, curr
        
        return prev1
