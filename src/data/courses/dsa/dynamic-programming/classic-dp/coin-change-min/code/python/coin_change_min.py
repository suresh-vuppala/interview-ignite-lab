class Solution:
    # Memoization (Top-Down)
    def coinChange(self, coins, amount):
        memo = {}
        def dp(amt):
            if amt == 0:
                return 0
            if amt < 0:
                return float('inf')
            if amt in memo:
                return memo[amt]
            
            min_coins = float('inf')
            for coin in coins:
                result = dp(amt - coin)
                if result != float('inf'):
                    min_coins = min(min_coins, 1 + result)
            
            memo[amt] = min_coins
            return min_coins
        
        result = dp(amount)
        return result if result != float('inf') else -1
    
    # Tabulation (Bottom-Up)
    def coinChangeTabulation(self, coins, amount):
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], 1 + dp[i - coin])
        
        return dp[amount] if dp[amount] != float('inf') else -1