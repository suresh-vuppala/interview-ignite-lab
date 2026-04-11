class Solution:
    def lengthOfLongestSubstring(self, s):
        last_idx, left, max_len = {}, 0, 0
        for right, c in enumerate(s):
            if c in last_idx and last_idx[c] >= left:
                left = last_idx[c] + 1   # Jump past duplicate
            last_idx[c] = right
            max_len = max(max_len, right - left + 1)
        return max_len