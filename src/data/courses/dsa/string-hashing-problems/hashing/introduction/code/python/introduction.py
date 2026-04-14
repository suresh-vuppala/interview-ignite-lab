# String Hashing Introduction
class Solution:
    def polynomialHash(self, s, base=31, mod=10**9+9):
        h = 0
        for ch in s:
            h = (h * base + ord(ch)) % mod
        return h

    def rollingHash(self, s, pattern_len, base=31, mod=10**9+9):
        # Compute hashes for all windows of size pattern_len
        hashes = []
        h = 0
        power = pow(base, pattern_len - 1, mod)
        for i in range(len(s)):
            h = (h * base + ord(s[i])) % mod
            if i >= pattern_len:
                h = (h - ord(s[i - pattern_len]) * power * base) % mod
            if i >= pattern_len - 1:
                hashes.append(h)
        return hashes
