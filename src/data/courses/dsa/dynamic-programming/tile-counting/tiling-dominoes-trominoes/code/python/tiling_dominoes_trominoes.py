class Solution:
    def numTilings(self, n):
        if n <= 2: return n
        MOD = 10**9 + 7
        a, b, c = 1, 2, 5
        for _ in range(4, n+1): a, b, c = b, c, (2*c + a) % MOD
        return c if n >= 4 else 5
