class Solution {
public:
    // Optimal: O(n) — Slide window, maintain freq counts
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        vector<int> pFreq(26,0), wFreq(26,0);
        for (char c : p) pFreq[c-'a']++;
        for (int i = 0; i < s.size(); i++) {
            wFreq[s[i]-'a']++;                           // Add entering char
            if (i >= (int)p.size()) wFreq[s[i-p.size()]-'a']--; // Remove leaving char
            if (wFreq == pFreq) result.push_back(i - p.size() + 1);
        }
        return result;
    }
};