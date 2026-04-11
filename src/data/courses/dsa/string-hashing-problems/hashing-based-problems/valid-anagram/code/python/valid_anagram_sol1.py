class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Sort: O(n log n) — Sorted anagrams are identical
        return sorted(s) == sorted(t)