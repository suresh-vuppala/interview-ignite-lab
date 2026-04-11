# ============================================================
# Minimum Window Substring
# ============================================================

from collections import Counter, defaultdict

# ============================================================
# Solution 1: Brute Force
# Time: O(N²×M) | Space: O(M)
# ============================================================
class Solution1:
    def minWindow(self, s: str, t: str) -> str:
        t_freq = Counter(t)
        min_window = ""
        for i in range(len(s)):
            w_freq = defaultdict(int)
            for j in range(i, len(s)):
                w_freq[s[j]] += 1
                if all(w_freq[c] >= t_freq[c] for c in t_freq):
                    if not min_window or j - i + 1 < len(min_window):
                        min_window = s[i:j+1]
                    break
        return min_window

# ============================================================
# Solution 2: Sliding Window + Frequency Tracking (Optimal)
# Time: O(N+M) | Space: O(N+M)
# ============================================================
class Solution2:
    def minWindow(self, s: str, t: str) -> str:
        t_freq = Counter(t)
        required = len(t_freq)   # Unique chars needed
        formed = 0               # Unique chars fully met
        w_freq = defaultdict(int)
        left = 0
        min_len, min_start = float('inf'), 0

        for right in range(len(s)):
            # Expand: add right character
            w_freq[s[right]] += 1
            if s[right] in t_freq and w_freq[s[right]] == t_freq[s[right]]:
                formed += 1

            # Shrink: minimize while valid
            while formed == required:
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_start = left

                # Remove left character
                w_freq[s[left]] -= 1
                if s[left] in t_freq and w_freq[s[left]] < t_freq[s[left]]:
                    formed -= 1
                left += 1

        return "" if min_len == float('inf') else s[min_start:min_start + min_len]
