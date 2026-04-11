class Solution {
public:
    // Optimal: O(n+m) — Frequency map
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> freq;
        for (int n : a) freq[n]++;       // Count in first array
        vector<int> result;
        for (int n : b) {
            if (freq[n] > 0) {           // Match found
                result.push_back(n);
                freq[n]--;               // Consume one occurrence
            }
        }
        return result;
    }
};