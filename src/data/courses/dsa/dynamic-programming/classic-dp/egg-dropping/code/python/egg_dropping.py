class Solution:
    def superEggDrop(self, K, N) -> int:
        dp = [[0]*(K+1) for _ in range(N+1)]
        t = 0
        while dp[t][K] < N:
            t += 1
            for k in range(1, K+1): dp[t][k] = 1 + dp[t-1][k-1] + dp[t-1][k]
        return t
