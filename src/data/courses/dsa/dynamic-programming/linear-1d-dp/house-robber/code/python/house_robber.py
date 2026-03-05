class Solution:
    # Memoization (Top-Down)
    def rob(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        
        memo = {}
        def dp(i):
            if i < 0:
                return 0
            if i in memo:
                return memo[i]
            memo[i] = max(nums[i] + dp(i-2), dp(i-1))
            return memo[i]
        
        return dp(n-1)
    
    # Tabulation (Bottom-Up)
    def robTabulation(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        
        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        for i in range(2, n):
            dp[i] = max(nums[i] + dp[i-2], dp[i-1])
        
        return dp[n-1]
    
    # Space Optimized
    def robOptimized(self, nums):
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        prev2, prev1 = nums[0], max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            curr = max(nums[i] + prev2, prev1)
            prev2, prev1 = prev1, curr
        
        return prev1