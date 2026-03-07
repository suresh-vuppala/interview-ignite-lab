class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^N) | Space: O(N)
    def maxProfitRecursive(self, prices):
        def solve(i, holding):
            if i == len(prices): return 0
            if holding:
                sell = prices[i] + solve(i + 1, False)
                hold = solve(i + 1, True)
                return max(sell, hold)
            else:
                buy = -prices[i] + solve(i + 1, True)
                skip = solve(i + 1, False)
                return max(buy, skip)
        return solve(0, False)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(N) | Space: O(N)
    def maxProfitMemo(self, prices):
        memo = {}
        def solve(i, holding):
            if i == len(prices): return 0
            if (i, holding) in memo: return memo[(i, holding)]
            if holding:
                sell = prices[i] + solve(i + 1, False)
                hold = solve(i + 1, True)
                memo[(i, holding)] = max(sell, hold)
            else:
                buy = -prices[i] + solve(i + 1, True)
                skip = solve(i + 1, False)
                memo[(i, holding)] = max(buy, skip)
            return memo[(i, holding)]
        return solve(0, False)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(N) | Space: O(N)
    def maxProfitTab(self, prices):
        n = len(prices)
        dp = [[0] * 2 for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0])
            dp[i][1] = max(prices[i] + dp[i + 1][0], dp[i + 1][1])
        return dp[0][0]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(N) | Space: O(1)
    def maxProfit(self, prices):
        min_price = float('inf')
        max_profit = 0
        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)
        return max_profit
