class Solution:
    def numWays(self, n, k):
        if n == 1: return k
        a, b = k, k * k
        for _ in range(3, n+1): a, b = b, (k-1) * (a + b)
        return b
