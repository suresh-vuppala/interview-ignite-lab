class Solution:
    # ============ MEMOIZATION (TOP-DOWN) ============
    def canPartitionMemo(self, nums):
        total = sum(nums)
        if total % 2 != 0:
            return False
        
        target = total // 2
        n = len(nums)
        memo = {}
        
        def dp(i, remaining):
            if remaining == 0:
                return True
            if i == n or remaining < 0:
                return False
            if (i, remaining) in memo:
                return memo[(i, remaining)]
            
            memo[(i, remaining)] = dp(i + 1, remaining - nums[i]) or dp(i + 1, remaining)
            return memo[(i, remaining)]
        
        return dp(0, target)
    
    # ============ TABULATION (BOTTOM-UP) ============
    def canPartitionTab(self, nums):
        total = sum(nums)
        if total % 2 != 0:
            return False
        
        target = total // 2
        n = len(nums)
        dp = [[False] * (target + 1) for _ in range(n + 1)]
        
        for i in range(n + 1):
            dp[i][0] = True
        
        for i in range(1, n + 1):
            for j in range(1, target + 1):
                if nums[i-1] <= j:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j - nums[i-1]]
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[n][target]
    
    # ============ SPACE OPTIMIZED ============
    def canPartition(self, nums):
        total = sum(nums)
        if total % 2 != 0:
            return False
        
        target = total // 2
        dp = [False] * (target + 1)
        dp[0] = True
        
        for num in nums:
            for j in range(target, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]
        
        return dp[target]
