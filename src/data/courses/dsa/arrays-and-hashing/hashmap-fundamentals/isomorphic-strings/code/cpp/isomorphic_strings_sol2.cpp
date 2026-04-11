class Solution {
public:
    // Pattern Encode: O(n) — Transform to first-occurrence indices
    bool isIsomorphic(string s, string t) {
        return encode(s) == encode(t);
    }
    string encode(string& str) {
        unordered_map<char, int> first;
        string pattern;
        for (char c : str) {
            if (!first.count(c)) first[c] = first.size();
            pattern += to_string(first[c]) + ",";
        }
        return pattern;
    }
};