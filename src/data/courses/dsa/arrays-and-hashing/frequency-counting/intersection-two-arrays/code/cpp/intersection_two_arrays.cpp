class Solution {
public:
    // O(n + m) time — Count frequencies, take minimum
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for (int n : nums1) freq[n]++;
        
        vector<int> result;
        for (int n : nums2) {
            if (freq[n] > 0) {
                result.push_back(n);
                freq[n]--; // Consume one occurrence
            }
        }
        return result;
    }
};