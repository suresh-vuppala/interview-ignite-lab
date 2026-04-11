# ============================================================
# Find All Anagrams in a String
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N×M) | Space: O(1)
# ============================================================
class Solution1:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        from collections import Counter
        result, m = [], len(p)
        pf = Counter(p)
        for i in range(len(s) - m + 1):
            if Counter(s[i:i+m]) == pf:
                result.append(i)
        return result

# ============================================================
# Solution 2: Sliding Window + Frequency Match (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        result = []
        if len(s) < len(p): return result

        m = len(p)
        pf = [0] * 26
        wf = [0] * 26

        for c in p: pf[ord(c) - 97] += 1

        for i in range(len(s)):
            wf[ord(s[i]) - 97] += 1              # Add entering
            if i >= m: wf[ord(s[i-m]) - 97] -= 1 # Remove leaving
            if i >= m - 1 and wf == pf:           # Compare
                result.append(i - m + 1)

        return result
