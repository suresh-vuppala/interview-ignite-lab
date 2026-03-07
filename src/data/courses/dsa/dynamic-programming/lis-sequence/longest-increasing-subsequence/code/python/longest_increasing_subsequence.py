class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^N) | Space: O(N)
    def lengthOfLISRecursive(self, nums):
        def solve(i, prev):
            if i == len(nums): return 0
            take = 0
            if prev == -1 or nums[i] > nums[prev]:
                take = 1 + solve(i + 1, i)
            skip = solve(i + 1, prev)
            return max(take, skip)
        return solve(0, -1)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(N²) | Space: O(N²)
    def lengthOfLISMemo(self, nums):
        memo = {}
        def solve(i, prev):
            if i == len(nums): return 0
            if (i, prev) in memo: return memo[(i, prev)]
            take = 0
            if prev == -1 or nums[i] > nums[prev]:
                take = 1 + solve(i + 1, i)
            skip = solve(i + 1, prev)
            memo[(i, prev)] = max(take, skip)
            return memo[(i, prev)]
        return solve(0, -1)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(N²) | Space: O(N)
    def lengthOfLISTab(self, nums):
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
    
    # ==================== SOLUTION 4: BINARY SEARCH (OPTIMAL) ====================
    # Time: O(N log N) | Space: O(N)
    def lengthOfLIS(self, nums):
        sub = []
        for num in nums:
            left, right = 0, len(sub)
            while left < right:
                mid = (left + right) // 2
                if sub[mid] < num:
                    left = mid + 1
                else:
                    right = mid
            if left == len(sub):
                sub.append(num)
            else:
                sub[left] = num
        return len(sub)
