class Solution {
public:
    // O(n) — Sliding window with hash map tracking distinct count
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            while (freq.size() > k) { // Shrink if too many distinct
                if (--freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};