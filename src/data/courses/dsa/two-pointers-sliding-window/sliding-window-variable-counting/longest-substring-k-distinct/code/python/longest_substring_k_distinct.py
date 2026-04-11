class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        from collections import defaultdict
        freq = defaultdict(int)
        left = max_len = 0
        for right, c in enumerate(s):
            freq[c] += 1
            while len(freq) > k:
                freq[s[left]] -= 1
                if freq[s[left]] == 0: del freq[s[left]]
                left += 1
            max_len = max(max_len, right - left + 1)
        return max_len