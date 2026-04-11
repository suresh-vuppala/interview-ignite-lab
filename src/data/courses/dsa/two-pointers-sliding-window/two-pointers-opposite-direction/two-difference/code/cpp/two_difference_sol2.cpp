// Sort + Two Pointers: O(n log n)
bool findPair(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int i = 0, j = 1;
    while (i < nums.size() && j < nums.size()) {
        if (i == j) { j++; continue; }
        int diff = nums[j] - nums[i];
        if (diff == target) return true;
        if (diff < target) j++;   // Difference too small
        else i++;                  // Difference too large
    }
    return false;
}