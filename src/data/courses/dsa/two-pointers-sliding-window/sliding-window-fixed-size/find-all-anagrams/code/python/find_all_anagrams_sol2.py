class Solution:
    def findAnagrams(self, s, p):
        result = []; m = len(p)
        if len(s) < m: return result
        pf, wf = [0]*26, [0]*26
        for c in p: pf[ord(c)-97] += 1
        for i in range(len(s)):
            wf[ord(s[i])-97] += 1
            if i >= m: wf[ord(s[i-m])-97] -= 1
            if wf == pf: result.append(i-m+1)
        return result