vector<int> firstNegative(vector<int>& nums, int k) {
    vector<int> result;
    for (int i = 0; i <= (int)nums.size()-k; i++) {
        int found = 0;
        for (int j = i; j < i+k; j++)
            if (nums[j] < 0) { found = nums[j]; break; }
        result.push_back(found);
    }
    return result;
}