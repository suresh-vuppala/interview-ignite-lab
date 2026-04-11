class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # Pattern Encode: O(n) — Compare first-occurrence indices
        def encode(string):
            mapping, pattern = {}, []
            for c in string:
                if c not in mapping: mapping[c] = len(mapping)
                pattern.append(mapping[c])
            return pattern
        return encode(s) == encode(t)