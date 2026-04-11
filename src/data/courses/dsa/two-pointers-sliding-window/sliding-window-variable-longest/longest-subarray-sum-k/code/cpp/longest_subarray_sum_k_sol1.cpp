int longestSubarray(vector<int>& nums, int k) {
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum <= k) maxLen = max(maxLen, j-i+1);
            else break; // Sum exceeded, no point extending
        }
    }
    return maxLen;
}