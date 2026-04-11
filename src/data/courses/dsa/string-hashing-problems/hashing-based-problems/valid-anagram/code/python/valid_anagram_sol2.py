class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Optimal: O(n) time — Counter comparison
        from collections import Counter
        return Counter(s) == Counter(t)