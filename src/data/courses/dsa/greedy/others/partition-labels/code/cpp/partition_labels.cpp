class Solution {
public:
    // O(n) — Track last occurrence, extend partition until current == last occurrence
    vector<int> partitionLabels(string s) {
        int last[26] = {};
        for (int i = 0; i < s.size(); i++) last[s[i]-'a'] = i;
        
        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i]-'a']); // Extend partition to include all of this char
            if (i == end) { // Reached the end of current partition
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};