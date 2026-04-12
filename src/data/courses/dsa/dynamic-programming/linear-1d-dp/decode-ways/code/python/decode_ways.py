class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0': return 0
        a, b = 1, 1
        for i in range(1, len(s)):
            c = 0
            if s[i] != '0': c += b
            two = int(s[i-1:i+1])
            if 10 <= two <= 26: c += a
            a, b = b, c
        return b
