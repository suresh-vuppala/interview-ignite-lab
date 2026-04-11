class Solution:
    def findAnagrams(self, s, p):
        from collections import Counter
        result, m = [], len(p)
        pf = Counter(p)
        for i in range(len(s)-m+1):
            if Counter(s[i:i+m]) == pf: result.append(i)
        return result