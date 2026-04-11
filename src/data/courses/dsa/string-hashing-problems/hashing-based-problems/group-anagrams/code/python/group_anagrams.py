# ============================================================
# Group Anagrams
# ============================================================

from typing import List
from collections import defaultdict

# ============================================================
# Solution 1: Sort Each String as Key
# Time: O(N × K log K) | Space: O(N × K)
# ============================================================
class Solution1:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)

        for s in strs:
            # Sorted string as key
            key = tuple(sorted(s))
            groups[key].append(s)

        return list(groups.values())

# ============================================================
# Solution 2: Character Frequency Count as Key (Optimal)
# Time: O(N × K) | Space: O(N × K)
# ============================================================
class Solution2:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)

        for s in strs:
            # Frequency count as key — tuple of 26 counts
            freq = [0] * 26
            for c in s:
                freq[ord(c) - ord('a')] += 1
            key = tuple(freq)

            groups[key].append(s)

        return list(groups.values())
