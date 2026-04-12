class Solution:
    def waysToReach(self, n):
        if n <= 1: return 1
        if n == 2: return 2
        a, b, c = 1, 1, 2
        for _ in range(3, n+1): a, b, c = b, c, a+b+c
        return c
