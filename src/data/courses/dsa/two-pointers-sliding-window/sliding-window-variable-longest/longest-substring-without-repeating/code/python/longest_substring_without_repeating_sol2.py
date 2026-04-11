class Solution:
    def lengthOfLongestSubstring(self, s):
        window, left, max_len = set(), 0, 0
        for right in range(len(s)):
            while s[right] in window: window.remove(s[left]); left += 1
            window.add(s[right]); max_len = max(max_len, right-left+1)
        return max_len