class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # O(n) time, O(1) space — Counter comparison
        from collections import Counter
        return Counter(s) == Counter(t)