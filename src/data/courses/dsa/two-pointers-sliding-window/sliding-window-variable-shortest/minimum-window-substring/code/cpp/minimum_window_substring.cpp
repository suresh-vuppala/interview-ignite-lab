class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;
        int left = 0, minLen = INT_MAX, minStart = 0, count = t.size();
        for (int right = 0; right < s.size(); right++) {
            if (mp.count(s[right])) {
                if (mp[s[right]] > 0) count--;
                mp[s[right]]--;
            }
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                if (mp.count(s[left])) {
                    mp[s[left]]++;
                    if (mp[s[left]] > 0) count++;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};