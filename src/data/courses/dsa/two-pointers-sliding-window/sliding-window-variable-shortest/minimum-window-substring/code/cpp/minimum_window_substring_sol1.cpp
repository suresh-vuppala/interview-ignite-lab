class Solution {
public:
    string minWindow(string s, string t) {
        string result; int minLen = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char,int> need;
            for (char c : t) need[c]++;
            for (int j = i; j < s.size(); j++) {
                if (need.count(s[j])) need[s[j]]--;
                bool valid = true;
                for (auto& [c,cnt] : need) if (cnt > 0) { valid = false; break; }
                if (valid && j-i+1 < minLen) { minLen = j-i+1; result = s.substr(i, minLen); break; }
            }
        }
        return result;
    }
};