# ============================================================
# Longest Substring with K Distinct Characters
# ============================================================

from collections import defaultdict

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(N)
# ============================================================
class Solution1:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        max_len = 0
        for i in range(len(s)):
            seen = set()
            for j in range(i, len(s)):
                seen.add(s[j])
                if len(seen) > k: break
                max_len = max(max_len, j - i + 1)
        return max_len

# ============================================================
# Solution 2: Sliding Window (Optimal)
# Time: O(N) | Space: O(K)
# ============================================================
class Solution2:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        freq = defaultdict(int)
        left = max_len = 0

        for right in range(len(s)):
            freq[s[right]] += 1

            while len(freq) > k:
                freq[s[left]] -= 1
                if freq[s[left]] == 0:
                    del freq[s[left]]
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len
