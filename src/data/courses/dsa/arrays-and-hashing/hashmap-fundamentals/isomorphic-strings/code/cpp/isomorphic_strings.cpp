class Solution {
public:
    // O(n) time, O(1) space — Two hash maps for bidirectional mapping
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> s2t, t2s; // Bidirectional mapping
        
        for (int i = 0; i < s.size(); i++) {
            // Check s->t mapping consistency
            if (s2t.count(s[i]) && s2t[s[i]] != t[i]) return false;
            // Check t->s mapping consistency (no two chars map to same)
            if (t2s.count(t[i]) && t2s[t[i]] != s[i]) return false;
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};