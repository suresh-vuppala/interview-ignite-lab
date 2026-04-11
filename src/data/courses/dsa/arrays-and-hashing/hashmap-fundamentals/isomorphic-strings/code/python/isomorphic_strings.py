class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # O(n) time — Check bidirectional mapping consistency
        return len(set(zip(s, t))) == len(set(s)) == len(set(t))