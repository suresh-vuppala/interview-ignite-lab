class Solution {
public:
    // Optimal: O(n) — Expand until valid, shrink to minimize
    string minWindow(string s, string t) {
        unordered_map<char,int> need, window;
        for (char c : t) need[c]++;
        int left = 0, formed = 0, required = need.size();
        int minLen = INT_MAX, start = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) formed++;
            // Shrink while valid
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left++];
                window[d]--;
                if (need.count(d) && window[d] < need[d]) formed--;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};