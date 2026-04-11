# ============================================================
# Longest Repeating Character Replacement
# ============================================================

from collections import defaultdict

# ============================================================
# Solution 1: Brute Force
# Time: O(N²×26) | Space: O(1)
# ============================================================
class Solution1:
    def characterReplacement(self, s: str, k: int) -> int:
        max_len = 0
        for i in range(len(s)):
            freq = defaultdict(int)
            max_f = 0
            for j in range(i, len(s)):
                freq[s[j]] += 1
                max_f = max(max_f, freq[s[j]])
                if (j - i + 1) - max_f <= k:
                    max_len = max(max_len, j - i + 1)
                else: break
        return max_len

# ============================================================
# Solution 2: Sliding Window + Max Frequency (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = defaultdict(int)
        left = max_freq = max_len = 0

        for right in range(len(s)):
            freq[s[right]] += 1
            max_freq = max(max_freq, freq[s[right]])

            # If replacements needed > k, shrink
            if (right - left + 1) - max_freq > k:
                freq[s[left]] -= 1
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len
