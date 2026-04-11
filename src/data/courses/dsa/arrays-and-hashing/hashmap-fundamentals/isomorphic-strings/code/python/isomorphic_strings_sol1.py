class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # Two Maps: O(n) — Bidirectional mapping check
        s2t, t2s = {}, {}
        for sc, tc in zip(s, t):
            if sc in s2t and s2t[sc] != tc: return False
            if tc in t2s and t2s[tc] != sc: return False
            s2t[sc] = tc; t2s[tc] = sc
        return True