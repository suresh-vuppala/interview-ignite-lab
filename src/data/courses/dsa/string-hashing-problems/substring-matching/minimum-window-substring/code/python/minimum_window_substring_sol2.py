class Solution:
    def minWindow(self, s, t):
        from collections import Counter, defaultdict
        need = Counter(t); window = defaultdict(int)
        left = formed = 0; required = len(need)
        min_len, start = float('inf'), 0
        for right in range(len(s)):
            c = s[right]; window[c] += 1
            if c in need and window[c] == need[c]: formed += 1
            while formed == required:
                if right-left+1 < min_len: min_len = right-left+1; start = left
                d = s[left]; window[d] -= 1
                if d in need and window[d] < need[d]: formed -= 1
                left += 1
        return '' if min_len == float('inf') else s[start:start+min_len]