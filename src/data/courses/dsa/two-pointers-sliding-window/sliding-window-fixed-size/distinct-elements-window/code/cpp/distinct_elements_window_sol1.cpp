vector<int> distinctInWindow(vector<int>& nums, int k) {
    vector<int> result;
    for (int i = 0; i <= (int)nums.size()-k; i++) {
        unordered_set<int> s(nums.begin()+i, nums.begin()+i+k);
        result.push_back(s.size());
    }
    return result;
}