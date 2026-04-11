# ============================================================
# Isomorphic Strings
# ============================================================

# ============================================================
# Solution 1: Two Hash Maps (Bidirectional)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution1:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map_st, map_ts = {}, {}

        for sc, tc in zip(s, t):
            # Check both directions for consistency
            if sc in map_st and map_st[sc] != tc:
                return False
            if tc in map_ts and map_ts[tc] != sc:
                return False

            map_st[sc] = tc
            map_ts[tc] = sc

        return True

# ============================================================
# Solution 2: First Occurrence Pattern Encoding
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def isIsomorphic(self, s: str, t: str) -> bool:
        def encode(string):
            mapping, pattern = {}, []
            for i, c in enumerate(string):
                if c not in mapping:
                    mapping[c] = i
                pattern.append(mapping[c])
            return pattern

        return encode(s) == encode(t)
