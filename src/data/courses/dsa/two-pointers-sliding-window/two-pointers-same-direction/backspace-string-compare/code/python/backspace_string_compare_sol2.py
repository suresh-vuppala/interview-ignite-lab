class Solution:
    def backspaceCompare(self, s, t):
        def get_next(string, i):
            skip = 0
            while i >= 0:
                if string[i] == '#': skip += 1; i -= 1
                elif skip > 0: skip -= 1; i -= 1
                else: break
            return i
        i, j = len(s)-1, len(t)-1
        while i >= 0 or j >= 0:
            i, j = get_next(s,i), get_next(t,j)
            if i>=0 and j>=0 and s[i]!=t[j]: return False
            if (i>=0) != (j>=0): return False
            i-=1; j-=1
        return True