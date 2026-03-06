class Solution:
    # ============ MEMOIZATION (TOP-DOWN) ============
    def maxSubArrayMemo(self, nums):
        n = len(nums)
        memo = {}
        
        def dp(i):
            if i == 0:
                return nums[0]
            if i in memo:
                return memo[i]
            memo[i] = max(nums[i], nums[i] + dp(i-1))
            return memo[i]
        
        return max(dp(i) for i in range(n))
    
    # ============ TABULATION (BOTTOM-UP) ============
    def maxSubArrayTab(self, nums):
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        max_sum = dp[0]
        
        for i in range(1, n):
            dp[i] = max(nums[i], nums[i] + dp[i-1])
            max_sum = max(max_sum, dp[i])
        
        return max_sum
    
    # ============ SPACE OPTIMIZED (KADANE'S) ============
    def maxSubArray(self, nums):
        max_ending_here = max_so_far = nums[0]
        
        for i in range(1, len(nums)):
            max_ending_here = max(nums[i], max_ending_here + nums[i])
            max_so_far = max(max_so_far, max_ending_here)
        
        return max_so_far
