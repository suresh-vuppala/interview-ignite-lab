class Solution {
public:
    // Optimal: Jump left past duplicate
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIdx; // char -> last seen index
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            if (lastIdx.count(s[right]) && lastIdx[s[right]] >= left)
                left = lastIdx[s[right]] + 1; // Jump past duplicate
            lastIdx[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};