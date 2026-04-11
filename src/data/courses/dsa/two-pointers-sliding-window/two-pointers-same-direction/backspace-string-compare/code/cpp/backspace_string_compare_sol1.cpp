class Solution {
public:
    // Stack: O(n+m) space
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
    string process(string& str) {
        string result;
        for (char c : str) {
            if (c == '#') { if (!result.empty()) result.pop_back(); }
            else result += c;
        }
        return result;
    }
};