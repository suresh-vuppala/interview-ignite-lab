class Solution:
    def change(self, amount, coins) -> int:
        dp = [0] * (amount+1); dp[0] = 1
        for coin in coins:
            for a in range(coin, amount+1): dp[a] += dp[a-coin]
        return dp[amount]
