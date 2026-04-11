// O(2^(n/2)) — Check if subset sum = totalSum/2 using MITM
bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;
    int target = total / 2, n = nums.size(), half = n / 2;
    
    unordered_set<int> leftSums;
    for (int m = 0; m < (1 << half); m++) {
        int s = 0; for (int i = 0; i < half; i++) if (m & (1<<i)) s += nums[i];
        leftSums.insert(s);
    }
    for (int m = 0; m < (1 << (n-half)); m++) {
        int s = 0; for (int i = 0; i < n-half; i++) if (m & (1<<i)) s += nums[half+i];
        if (leftSums.count(target - s)) return true;
    }
    return false;
}