class Solution:
    # ============ MEMOIZATION (TOP-DOWN) ============
    def robMemo(self, nums):
        if len(nums) == 1:
            return nums[0]
        
        def robLinear(arr):
            memo = {}
            def dp(i):
                if i < 0:
                    return 0
                if i in memo:
                    return memo[i]
                memo[i] = max(arr[i] + dp(i-2), dp(i-1))
                return memo[i]
            return dp(len(arr) - 1)
        
        return max(robLinear(nums[:-1]), robLinear(nums[1:]))
    
    # ============ TABULATION (BOTTOM-UP) ============
    def rob(self, nums):
        if len(nums) == 1:
            return nums[0]
        
        def robLinear(arr):
            if not arr:
                return 0
            if len(arr) == 1:
                return arr[0]
            prev2, prev1 = arr[0], max(arr[0], arr[1])
            for i in range(2, len(arr)):
                curr = max(arr[i] + prev2, prev1)
                prev2, prev1 = prev1, curr
            return prev1
        
        return max(robLinear(nums[:-1]), robLinear(nums[1:]))
