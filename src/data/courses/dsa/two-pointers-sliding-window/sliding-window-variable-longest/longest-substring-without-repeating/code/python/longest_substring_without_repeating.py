# ============================================================
# Longest Substring Without Repeating Characters
# ============================================================

# ============================================================
# Solution 1: Brute Force
# Time: O(N³) | Space: O(N)
# ============================================================
class Solution1:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        for i in range(len(s)):
            seen = set()
            for j in range(i, len(s)):
                if s[j] in seen: break
                seen.add(s[j])
                max_len = max(max_len, j - i + 1)
        return max_len

# ============================================================
# Solution 2: Sliding Window + Hash Set
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window = set()
        left = max_len = 0
        for right in range(len(s)):
            while s[right] in window:
                window.remove(s[left])
                left += 1
            window.add(s[right])
            max_len = max(max_len, right - left + 1)
        return max_len

# ============================================================
# Solution 3: Last Index Map (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution3:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = {}  # char → last index
        left = max_len = 0

        for right, char in enumerate(s):
            if char in last_seen and last_seen[char] >= left:
                left = last_seen[char] + 1  # Jump past duplicate
            last_seen[char] = right
            max_len = max(max_len, right - left + 1)

        return max_len
