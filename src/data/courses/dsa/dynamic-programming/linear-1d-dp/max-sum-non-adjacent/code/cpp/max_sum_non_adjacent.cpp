class Solution {
public:
    int maxSumNonAdjacent(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return max(0, nums[0]);
        int prev2 = max(0, nums[0]), prev1 = max(prev2, nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1; prev1 = curr;
        }
        return prev1;
    }
};
