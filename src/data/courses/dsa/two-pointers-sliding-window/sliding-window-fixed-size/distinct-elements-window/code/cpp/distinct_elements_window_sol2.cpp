vector<int> distinctInWindow(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;                              // Add entering
        if (i >= k) {
            freq[nums[i-k]]--;                        // Remove leaving
            if (freq[nums[i-k]] == 0) freq.erase(nums[i-k]);
        }
        if (i >= k-1) result.push_back(freq.size()); // Distinct = map size
    }
    return result;
}