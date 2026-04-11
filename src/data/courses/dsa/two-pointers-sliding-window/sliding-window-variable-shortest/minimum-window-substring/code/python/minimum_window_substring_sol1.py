class Solution:
    def minWindow(self, s, t):
        from collections import Counter
        result, min_len = '', float('inf')
        for i in range(len(s)):
            need = Counter(t)
            for j in range(i, len(s)):
                if s[j] in need: need[s[j]] -= 1
                if all(v <= 0 for v in need.values()):
                    if j-i+1 < min_len: min_len = j-i+1; result = s[i:j+1]
                    break
        return result