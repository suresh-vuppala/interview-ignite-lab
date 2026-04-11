# ============================================================
# Valid Anagram
# ============================================================

from collections import Counter

# ============================================================
# Solution 1: Sort Both Strings
# Time: O(N log N) | Space: O(N)
# ============================================================
class Solution1:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        # Sort both — anagrams become identical
        return sorted(s) == sorted(t)

# ============================================================
# Solution 2: Frequency Count Array (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        # Pythonic: Counter comparison in O(N)
        return Counter(s) == Counter(t)
