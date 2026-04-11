class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int m = p.size();
        vector<int> pFreq(26, 0);
        for (char c : p) pFreq[c-'a']++;
        for (int i = 0; i <= (int)s.size()-m; i++) {
            vector<int> wFreq(26, 0);
            for (int j = i; j < i+m; j++) wFreq[s[j]-'a']++;
            if (wFreq == pFreq) result.push_back(i);
        }
        return result;
    }
};