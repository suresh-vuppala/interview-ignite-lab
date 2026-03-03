class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int left = 0, maxCount = 0, maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            maxCount = max(maxCount, ++count[s[right] - 'A']);
            while (right - left + 1 - maxCount > k) {
                count[s[left++] - 'A']--;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};