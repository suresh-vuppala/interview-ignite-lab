class Solution:
    def coinChange(self, coins, amount) -> int:
        dp = [amount+1] * (amount+1); dp[0] = 0
        for coin in coins:
            for a in range(coin, amount+1):
                dp[a] = min(dp[a], dp[a-coin] + 1)
        return dp[amount] if dp[amount] <= amount else -1
