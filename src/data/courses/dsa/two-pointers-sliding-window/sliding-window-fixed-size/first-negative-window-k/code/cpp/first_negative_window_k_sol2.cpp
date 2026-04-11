vector<int> firstNegative(vector<int>& nums, int k) {
    deque<int> negIdx; // Indices of negative numbers
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) negIdx.push_back(i);           // Track negatives
        if (i >= k - 1) {
            while (!negIdx.empty() && negIdx.front() < i-k+1) negIdx.pop_front(); // Remove expired
            result.push_back(negIdx.empty() ? 0 : nums[negIdx.front()]);
        }
    }
    return result;
}